/*
 * Copyright 2016 salesforce.com, inc.
 * All rights reserved.
 *
 * Use of this software is subject to the salesforce.com Developerforce Terms of
 * Use and other applicable terms that salesforce.com may make available, as may be
 * amended from time to time. You may not decompile, reverse engineer, disassemble,
 * attempt to derive the source code of, decrypt, modify, or create derivative
 * works of this software, updates thereto, or any part thereof. You may not use
 * the software to engage in any development activity that infringes the rights of
 * a third party, including that which interferes with, damages, or accesses in an
 * unauthorized manner the servers, networks, or other properties or services of
 * salesforce.com or any third party.
 *
 * WITHOUT LIMITING THE GENERALITY OF THE FOREGOING, THE SOFTWARE IS PROVIDED
 * "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED. IN NO EVENT SHALL
 * SALESFORCE.COM HAVE ANY LIABILITY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO,
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, PUNITIVE, OR CONSEQUENTIAL DAMAGES, OR
 * DAMAGES BASED ON LOST PROFITS, DATA OR USE, IN CONNECTION WITH THE SOFTWARE,
 * HOWEVER CAUSED AND, WHETHER IN CONTRACT, TORT OR UNDER ANY OTHER THEORY OF
 * LIABILITY, WHETHER OR NOT YOU HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGES.
 */

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SCServiceCloud;
/**
 Delegate protocol to interact with the Service Cloud Kit SDK, and to make decisions on behalf of the SDK.
 */
@protocol SCServiceCloudDelegate <NSObject>

@optional

/**
 Tells the delegate when the interface is about to be displayed.

 @param serviceCloud  Service Cloud interface instance.
 @param controller View controller being displayed.
 @param animated   `YES` if the presentation is animated.
 */
- (void)serviceCloud:(SCServiceCloud *)serviceCloud willDisplayViewController:(UIViewController*)controller animated:(BOOL)animated;

/**
 Calls the delegate after the interface was displayed.

 @param serviceCloud  Service Cloud interface instance.
 @param controller View controller being displayed.
 @param animated   `YES` if the presentation was animated.
 */
- (void)serviceCloud:(SCServiceCloud *)serviceCloud didDisplayViewController:(UIViewController*)controller animated:(BOOL)animated;

/**
 Asks the delegate to provide a `UIViewControllerTransitioningDelegate` used when a view controller is about to be presented.
 
 By default, Service Cloud Kit uses custom controllers for presentation and for transition animations. If you wish to customize the default behavior, implement this method and return an object conforming to `UIViewControllerTransitioningDelegate`.
 
 @param serviceCloud Service Cloud interface instance.
 @param controller   View controller about to be presented.

 @return Transitioning delegate that should control the controller presentation, or `nil` to accept the system defaults.
 */
- (nullable NSObject<UIViewControllerTransitioningDelegate>*)serviceCloud:(SCServiceCloud *)serviceCloud transitioningDelegateForViewController:(UIViewController*)controller;

/**
 Asks the delegate whether the specified action button should be present.

 The value of the action name can be one of these constants (defined in Service Cloud Kit):

 - `SCSActionCasePublisher`: for the case publisher action
 - `SCSActionCaseList`: for the case list action
 - `SCSActionArticleSearch`: for the knowledge article search action

 @param serviceCloud Service Cloud interface instance.
 @param name Name representing the action in question.
 @return `YES` if the action button should be visible; `NO` if the action button should be omitted.
 */
- (BOOL)serviceCloud:(SCServiceCloud *)serviceCloud shouldShowActionWithName:(NSString*)name;

/**
 Asks the delegate whether authentication should be performed for the specified service.

 The value of the service name can be one of these constants (defined in Service Cloud Kit):

 - `SCServiceTypeCases`: for the Case Management service
 - `SCServiceTypeKnowledge`: for the Knowledge service
 
 If the delegate returns `YES` to this method, it is the responsibility of the receiver to supply the new user account object to the supplied completion block.  The value supplied to the completion block will replace the [account]([SCServiceCloud account]) property.

 @param serviceCloud  Service Cloud interface instance.
 @param service The associated service.
 @param completion The completion block you should call when you've retrieved the user account.
 @return `YES` if the receiver plans to supply authentication information for this service, otherwise `NO` if the current account credentials are sufficient.
 */
- (BOOL)serviceCloud:(SCServiceCloud*)serviceCloud shouldAuthenticateService:(NSString*)service completion:(void(^)(SFUserAccount * _Nullable account))completion;

/**
 Tells the delegate when there is an error in authenticating Case Management or Knowledge.
 
 @param serviceCloud  Service Cloud interface instance.
 @param error The error message associated with the failure.
 */
- (void)serviceCloud:(SCServiceCloud*)serviceCloud serviceAuthenticationFailedWithError:(NSError*)error;

@end

NS_ASSUME_NONNULL_END
