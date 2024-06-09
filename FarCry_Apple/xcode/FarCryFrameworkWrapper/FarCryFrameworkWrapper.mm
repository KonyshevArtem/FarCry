#import "FarCryFrameworkWrapper.h"
#import "FarCryFramework.h"

@implementation FarCryFrameworkWrapper

+ (void) Initialize:(void*)graphicsDevice graphicsBackend:(NSString*)graphicsBackend
{
    //FarCryFramework::Initialize(graphicsDevice, [graphicsBackend UTF8String]);
}

+ (void) TickMainLoop:(void*)commandBufferPtr backbufferDescriptor:(void*)backbufferDescriptor width:(int)width height:(int)height
{
    //FarCryFramework::TickMainLoop(commandBufferPtr, backbufferDescriptor, width, height);
}

+ (void) Shutdown
{
    //FarCryFramework::Shutdown();
}

+ (bool) ShouldCloseWindow
{
    return false;
    //return FarCryFramework::ShouldCloseWindow();
}

+ (void) ProcessMouseMove:(float)x y:(float)y
{
    //FarCryFramework::ProcessMouseMove(x, y);
}

+ (void) ProcessKeyPress:(char)key pressed:(bool)pressed
{
    //FarCryFramework::ProcessKeyPress(key, pressed);
}

@end
