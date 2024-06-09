#ifndef FarCryViewController_h
#define FarCryViewController_h

#if defined(TARGET_IOS) || defined(TARGET_TVOS)
@import UIKit;
#define PlatformViewController UIViewController
#else
@import AppKit;
#define PlatformViewController NSViewController
#endif

@interface FarCryViewController : PlatformViewController

- (CGSize) getViewSize;

@end

@interface TrackingAreaProvider : NSObject

- (void) updateTrackingArea:(NSView*)view;

@end

#endif /* FarCryViewController_h */
