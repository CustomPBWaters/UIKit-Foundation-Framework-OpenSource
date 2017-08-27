/*
 * UIPresentationController.h
 * UIKit
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2014-2016
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
 */
 
#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIApplication.h>
#import <UIKit/UIViewController.h>
#import <UIKit/UIAppearance.h>
#import <UIKit/UIGeometry.h>
#import <UIKit/UITraitCollection.h>
#import <UIKit/UIViewControllerTransitionCoordinator.h>
#import <UIKit/UIFocus.h>

NS_ASSUME_NONNULL_BEGIN

@class UIPresentationController;

@protocol UIAdaptivePresentationControllerDelegate <NSObject>

@optional

/* For iOS8.0, the only supported adaptive presentation styles are UIModalPresentationFullScreen and UIModalPresentationOverFullScreen. */
- (UIModalPresentationStyle)adaptivePresentationStyleForPresentationController:(UIPresentationController *)controller;

// Returning UIModalPresentationNone will indicate that an adaptation should not happen.
- (UIModalPresentationStyle)adaptivePresentationStyleForPresentationController:(UIPresentationController *)controller traitCollection:(UITraitCollection *)traitCollection NS_AVAILABLE_IOS(8_3);

/* If this method is not implemented, or returns nil, then the originally presented view controller is used. */
- (nullable UIViewController *)presentationController:(UIPresentationController *)controller viewControllerForAdaptivePresentationStyle:(UIModalPresentationStyle)style;

// If there is no adaptation happening and an original style is used UIModalPresentationNone will be passed as an argument.
- (void)presentationController:(UIPresentationController *)presentationController willPresentWithAdaptiveStyle:(UIModalPresentationStyle)style transitionCoordinator:(nullable id <UIViewControllerTransitionCoordinator>)transitionCoordinator NS_AVAILABLE_IOS(8_3);


@end

NS_CLASS_AVAILABLE_IOS(8_0) @interface UIPresentationController : NSObject <UIAppearanceContainer, UITraitEnvironment, UIContentContainer, UIFocusEnvironment>

@property(nonatomic, strong, readonly) UIViewController *presentingViewController;
@property(nonatomic, strong, readonly) UIViewController *presentedViewController;

@property(nonatomic, readonly) UIModalPresentationStyle presentationStyle;

// The view in which a presentation occurs. It is an ancestor of both the presenting and presented view controller's views.
// This view is being passed to the animation controller.
@property(nullable, nonatomic, readonly, strong) UIView *containerView;

@property(nullable, nonatomic, weak) id <UIAdaptivePresentationControllerDelegate> delegate;

- (instancetype)initWithPresentedViewController:(UIViewController *)presentedViewController presentingViewController:(nullable UIViewController *)presentingViewController NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

// By default this implementation defers to the delegate, if one exists, or returns the current presentation style. UIFormSheetPresentationController, and
// UIPopoverPresentationController override this implementation to return UIModalPresentationStyleFullscreen if the delegate does not provide an
// implementation for adaptivePresentationStyleForPresentationController:
#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly) UIModalPresentationStyle adaptivePresentationStyle;
#else
- (UIModalPresentationStyle)adaptivePresentationStyle;
#endif
- (UIModalPresentationStyle)adaptivePresentationStyleForTraitCollection:(UITraitCollection *)traitCollection NS_AVAILABLE_IOS(8_3);

- (void)containerViewWillLayoutSubviews;
- (void)containerViewDidLayoutSubviews;

// A view that's going to be animated during the presentation. Must be an ancestor of a presented view controller's view
// or a presented view controller's view itself.
// (Default: presented view controller's view)
#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly, nullable) UIView *presentedView;

// Position of the presented view in the container view by the end of the presentation transition.
// (Default: container view bounds)
@property(nonatomic, readonly) CGRect frameOfPresentedViewInContainerView;

// By default each new presentation is full screen.
// This behavior can be overriden with the following method to force a current context presentation.
// (Default: YES)
@property(nonatomic, readonly) BOOL shouldPresentInFullscreen;

// Indicate whether the view controller's view we are transitioning from will be removed from the window in the end of the
// presentation transition
// (Default: NO)
@property(nonatomic, readonly) BOOL shouldRemovePresentersView;
#else
- (nullable UIView *)presentedView;

// Position of the presented view in the container view by the end of the presentation transition.
// (Default: container view bounds)
- (CGRect)frameOfPresentedViewInContainerView;

// By default each new presentation is full screen.
// This behavior can be overriden with the following method to force a current context presentation.
// (Default: YES)
- (BOOL)shouldPresentInFullscreen;

// Indicate whether the view controller's view we are transitioning from will be removed from the window in the end of the
// presentation transition
// (Default: NO)
- (BOOL)shouldRemovePresentersView;
#endif

- (void)presentationTransitionWillBegin;
- (void)presentationTransitionDidEnd:(BOOL)completed;
- (void)dismissalTransitionWillBegin;
- (void)dismissalTransitionDidEnd:(BOOL)completed;

// Modifies the trait collection for the presentation controller.
@property(nullable, nonatomic, copy) UITraitCollection *overrideTraitCollection;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END

