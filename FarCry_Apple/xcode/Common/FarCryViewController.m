#import "FarCryViewController.h"
#import "FarCryFrameworkWrapper.h"
#import <Foundation/Foundation.h>

@implementation FarCryViewController

- (CGSize) getViewSize
{
    return CGSizeMake(0, 0);
}

- (void) mouseMoved:(NSEvent *)event
{
    NSPoint point = event.locationInWindow;
    [FarCryFrameworkWrapper ProcessMouseMove:point.x y: [self getViewSize].height - point.y];
}

- (void) keyPress:(NSEvent *)event pressed:(bool)pressed
{
    [FarCryFrameworkWrapper ProcessKeyPress:[[event.characters uppercaseString] characterAtIndex:0] pressed:pressed];
}

- (void) keyDown:(NSEvent *)event
{
    [self keyPress:event pressed:true];
}

- (void) keyUp:(NSEvent *)event
{
    [self keyPress:event pressed:false];
}

@end

@implementation TrackingAreaProvider

NSTrackingArea *trackingArea;

- (void)updateTrackingArea:(NSView *)view
{
    if (trackingArea != nil)
    {
        [view removeTrackingArea:trackingArea];
    }
    
    NSTrackingAreaOptions options = NSTrackingMouseEnteredAndExited | NSTrackingMouseMoved | NSTrackingActiveInKeyWindow;
    trackingArea = [[NSTrackingArea alloc] initWithRect:[view bounds] options:options owner:view userInfo:nil];
    [view addTrackingArea:trackingArea];
}

@end
