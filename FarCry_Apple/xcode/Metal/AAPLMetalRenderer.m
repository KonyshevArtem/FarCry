#import "AAPLMetalRenderer.h"
#import "FarCryFrameworkWrapper.h"

static const MTLPixelFormat AAPLDepthFormat = MTLPixelFormatDepth32Float;
static const MTLPixelFormat AAPLColorFormat = MTLPixelFormatBGRA8Unorm;

/// Main class that performs the rendering.
@implementation AAPLMetalRenderer

id<MTLDevice>        _device;
id<MTLCommandQueue>  _commandQueue;

id<MTLDepthStencilState>   _depthState;

CGSize _viewSize;

/// Initialize the renderer with the MetalKit view that references the Metal device you render with.
/// You also use the MetalKit view to set the pixel format and other properties of the drawable.
- (nonnull instancetype)initWithMetalKitView:(nonnull MTKView *)mtkView
{
    self = [super init];
    if(self)
    {
        _device = mtkView.device;
        _commandQueue = [_device newCommandQueue];

        mtkView.colorPixelFormat        = AAPLColorFormat;
        mtkView.depthStencilPixelFormat = AAPLDepthFormat;
        {
            // Configure a combined depth and stencil descriptor that enables the creation
            // of an immutable depth and stencil state object.
            MTLDepthStencilDescriptor *depthStencilDesc = [[MTLDepthStencilDescriptor alloc] init];
            depthStencilDesc.depthCompareFunction = MTLCompareFunctionLess;
            depthStencilDesc.depthWriteEnabled = YES;
            _depthState = [_device newDepthStencilStateWithDescriptor:depthStencilDesc];
        }
        
        [FarCryFrameworkWrapper Initialize:(void*)_device graphicsBackend:@"Metal"];
    }

    return self;
}

- (void) dealloc
{
    [FarCryFrameworkWrapper Shutdown];
}

/// Called whenever the view orientation, layout, or size changes.
- (void) mtkView:(nonnull MTKView *)view drawableSizeWillChange:(CGSize)size
{
    _viewSize = size;
}

/// Called whenever the view needs to render.
- (void) drawInMTKView:(nonnull MTKView *)view
{
    if ([FarCryFrameworkWrapper ShouldCloseWindow])
    {
        [[view window] performClose:self];
        return;
    }
    
    MTLRenderPassDescriptor* renderPassDescriptor = [view currentRenderPassDescriptor];
    [[[renderPassDescriptor colorAttachments] objectAtIndexedSubscript:0] setLoadAction:MTLLoadActionDontCare];

    id<MTLCommandBuffer> commandBuffer = [_commandQueue commandBuffer];
    
    [FarCryFrameworkWrapper TickMainLoop:(void*)commandBuffer backbufferDescriptor:(void*)renderPassDescriptor width:_viewSize.width height:_viewSize.height];
    
    [commandBuffer presentDrawable:view.currentDrawable];
    [commandBuffer commit];
}

- (CGSize) getViewSize
{
    return _viewSize;
}

@end
