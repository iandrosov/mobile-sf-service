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

/**
 * A `SCSPrechatObject` specifies a pre-chat field that you can send directly to the agent.
 * This object contains a label and a value.
 *
 * This object does not prompt the user for information. To create a field that the
 * user can fill in, refer to `SCSPrechatTextInputObject`.
 *
 * This object must be added to your chat configuration using [SCSChatConfiguration prechatFields].
 */
@interface SCSPrechatObject : NSObject

///---------------------------------
/// @name Properties
///---------------------------------

/**
 *  Name of pre-chat detail shown to agent.
 */
@property (nonatomic, strong, readonly) NSString *label;

/**
 *  Value of the pre-chat detail.
 */
@property (nonatomic, strong, readonly) NSString *value;

///---------------------------------
/// @name Initialization
///---------------------------------

/**
 *  Instantiates an `SCSPrechatObject` object for use with [SCSChatConfiguration prechatFields]
 *
 *  @param label    The identifying label to show to the agent in the Service Console.
 *  @param value    The value of the field.
 *
 *  @return The `SCSPrechatObject` instance.
 */
- (instancetype)initWithLabel:(NSString *)label value:(NSString *)value NS_DESIGNATED_INITIALIZER;

@end
