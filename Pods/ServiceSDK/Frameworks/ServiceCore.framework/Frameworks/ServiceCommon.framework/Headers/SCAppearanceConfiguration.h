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

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SCCDefines.h"

NS_ASSUME_NONNULL_BEGIN

/// The primary brand color key, used for primary visual elements such as header colors.
SC_EXTERN NSString * const SCSAppearancePrimaryBrandColor;

/// The secondary brand color key, used for action button colors.
SC_EXTERN NSString * const SCSAppearanceSecondaryBrandColor;

/// The primary text color key, used for the majority of text.
SC_EXTERN NSString * const SCSAppearanceContrastPrimaryColor;

/// The secondary text color key, used for sub category header text.
SC_EXTERN NSString * const SCSAppearanceContrastSecondaryColor;

/// The background brand color key, used for primary visual elements such as header colors.
SC_EXTERN NSString * const SCSAppearanceContrastInvertedColor;

/// The overlay background brand color key, used for semi-transparent overlay colors.
SC_EXTERN NSString * const SCSAppearanceOverlayColor;

/// The main background color key.
SC_EXTERN NSString * const SCSAppearanceFeedbackPrimaryColor;
SC_EXTERN NSString * const SCSAppearanceFeedbackSecondaryColor;
SC_EXTERN NSString * const SCSAppearanceFeedbackTertiaryColor;

/// The navigation background color key.
SC_EXTERN NSString * const SCSAppearanceNavbarBackgroundColor;

/// The text color key used for header text.
SC_EXTERN NSString * const SCSAppearanceTitleTextColor;

/// The text color key used for actionable labels, such as action buttons and case submit buttons.
SC_EXTERN NSString * const SCSAppearanceBrandContrastColor;

/// The tertiary color key is a calculated value used for unselected article backgrounds, footer backgrounds, and other secondary areas.
/// The value is calculated by SCSAppearanceContrastInvertedColor mixed with the SCSAppearanceContrastSecondaryColor with a 10% alpha applied.
SC_EXTERN NSString * const SCSAppearanceContrastTertiaryColor;

/// The quaternary color key is a calculated value used for the tint coloring of accessory images.
/// This value is calculated by SCSAppearanceContrastInvertedColor mixed with the SCSAppearanceContrastSecondaryColor with a 50% alpha applied.
SC_EXTERN NSString * const SCSAppearanceContrastQuaternaryColor;

@class SCAppearanceConfiguration;

/* SCFontWeight */
SC_EXTERN NSInteger const SCFontWeightLight;
SC_EXTERN NSInteger const SCFontWeightRegular;
SC_EXTERN NSInteger const SCFontWeightBold;

/**
 Delegate protocol for responding to style and branding customization requests at runtime.
 */
@protocol SCAppearanceConfigurationDelegate <NSObject>

@optional

/**
 Tells the delegate when appearance configuration updates will be applied.
 @param configuration The appearance configuration to be applied.
 */
- (void)appearanceConfigurationWillApplyUpdates:(SCAppearanceConfiguration*)configuration;

/**
 Tells the delegate when appearance configuration updates have been applied.
 @param configuration The appearance configuration that was applied.
 */
- (void)appearanceConfigurationDidApplyUpdates:(SCAppearanceConfiguration*)configuration;

@end

/**
 Configuration class used to customize the settings that influence the branding and coloring of UI elements used throughout ServiceCloudKit.
 
 Pass an instance of this class to the `[appearanceConfiguration]([SCServiceCloud appearanceConfiguration])` property on the `SCServiceCloud` shared instance to set the appearance.
 */
@interface SCAppearanceConfiguration : NSObject

/**
 The appearance delegate, used for branding customization.
 @see SCAppearanceConfigurationDelegate
 */
@property (nonatomic, weak, nullable) NSObject<SCAppearanceConfigurationDelegate> *delegate;

/**
 Property indicating whether any `UIAppearance` settings have been applied from this configuration instance.
 */
@property (nonatomic, readonly, getter=isAppearanceApplied) BOOL appearanceApplied;

/**
 Controls whether the `UIAppearance` selectors need to be updated.

 @see applyAppearanceUpdatesIfNeeded
 */
- (void)setNeedsAppearanceUpdates;

/**
 Updates the `UIAppearance` selectors to reflect the current state of the configuration object.
 
 This method can be used to force appearance updates to occur at a particular time, or if there is cause for some branding changes to be reapplied.  Note that updates are only applied if the appearance settings have indeed changed.
 
 @see setNeedsAppearanceUpdates
 */
- (void)applyAppearanceUpdatesIfNeeded;

@end

@interface SCAppearanceConfiguration (Colors)

/**
 Sets the color for the named `SCAppearanceConfiguration` constant.

 @param color The color to set.
 @param name  The branding token name to set the color for.
 */
- (void)setColor:(UIColor*)color forName:(NSString*)name;

/**
 Returns the color set by the `setColor:forName:` method for the named `SCAppearanceConfiguration` constant.
 
 If no value has been specified, the default value is returned.
 
 @param name The branding token name to retrieve a color for.
 @return The color associated with that branding token, or `nil` if the branding token name is invalid.
 */
- (nullable UIColor*)colorForName:(NSString*)name;

@end

@interface SCAppearanceConfiguration (Images)

/**
 Sets the image for a named `SCAppearanceConfiguration` constant.
 
 @param image           The image to set.
 @param traitCollection The trait collection the image will be used for, if applicable.
 @param name            The branding token name to set the image for.
 */
- (void)setImage:(UIImage*)image compatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection forName:(NSString*)name;

/**
 Returns the image set by the `setImage:forName:` method for the named `SCAppearanceConfiguration` constant.
 
 If no value has been specified, the default value is returned.
 
 @param name            The image name to retrieve an image for.
 @param traitCollection The trait collection the image will be used for, if applicable.
 */
- (nullable UIImage*)imageForName:(NSString*)name compatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection;

@end

@interface SCAppearanceConfiguration (Fonts)

/**
 Sets `fontDescriptor` for specified weight; used to create and set the `UIFont` on the labels.
 
 If `UIFontDescriptorSizeAttribute` is set on the `fontDescriptor`, it is used to set the font size.
 If not, the SDK sets the font size appropriately.
 
 @param fontDescriptor `UIFontDescriptor` instance to be used for creating `UIFont`.
 @param fileName Name of the font file contained in the bundle, or `nil` when using a built-in system font.
 @param weight A value from the `SCFontWeight` enum.
 */
- (void)setFontDescriptor:(UIFontDescriptor*)fontDescriptor fontFileName:(nullable NSString*)fileName forWeight:(NSInteger)weight;

/**
 Returns the `fontDescriptor` for the specified weight.
 
 If no value has been specified, the default value is returned.
 Default values:
 
 - `Helvetica Neue - Light` for `SCFontWeightLight`,
 - `Helvetica Neue` for `SCFontWeightRegular`,
 - `Helvetica Neue - Semibold` for `SCFontWeightBold`.

 @param weight A value from the `SCFontWeight` enum.
 */
- (UIFontDescriptor*)getFontDescriptorForWeight:(NSInteger)weight __deprecated_msg("Method deprecated. Use `getFontDescriptorForWeight:size:`");

/**
 Returns the `fontDescriptor` for the specified weight.

 If no value has been specified, the default value is returned.
 Default values iOS 8 & Below:

 - `Helvetica Neue - Thin` for `SCFontWeightLight`,
 - `Helvetica Neue - Regular` for `SCFontWeightRegular`,
 - `Helvetica Neue - MediumP4` for `SCFontWeightBold`.

 Default values iOS 9 & Above:

 - `San Francisco` with `UIFontWeightThin` for `SCFontWeightLight`
 - `San Francisco` with `UIFontWeightRegular` for `SCFontWeightRegular`
 - `San Francisco` with `UIFontWeightSemibold` for `SCFontWeightBold`

 @param weight A value from the `SCFontWeight` enum.
 @param size   Size of the desired font
 */
- (UIFontDescriptor*)getFontDescriptorForWeight:(NSInteger)weight size:(CGFloat)size;

- (nullable NSString*)getFontFileNameForWeight:(NSInteger)weight;

@end

@interface SCAppearanceConfiguration (AttributedText)

/**
 Sets the attributed text attributes for the named `SCAppearanceConfiguration` constant.

 @param attributes      The text attributes to set.
 @param traitCollection The trait collection these attributes will be used for, if applicable.
 @param name            The branding token name to set the attributes for.
 */
- (void)setTextAttributes:(NSDictionary<NSString *, id>*)attributes compatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection forName:(NSString*)name;

/**
 Returns the text attribute set by the `setTextAttributes:compatibleWithTraitCollection:forName:` 
 method for the named `SCAppearanceConfiguration` constant.
 
 If no value has been specified, the default value is returned.

 @param name            The branding token name to retrieve the attributes for.
 @param traitCollection The trait collection these attributes will be used for, if applicable.
 */
- (nullable NSDictionary<NSString *, id>*)textAttributesForName:(NSString*)name compatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection;

@end

NS_ASSUME_NONNULL_END

