//
//  TuyaSecurityUser.h
//  BlocksKit
//
//  Created by Tuya.Inc on 2020/5/7.
//

#import <Foundation/Foundation.h>
#import <TuyaSmartBaseKit/TuyaSmartBaseKit.h>

@class TuyaSecurityUserServiceModel;

typedef void (^GetUserServiceHandler)(TuyaSecurityUserServiceModel * _Nullable userServiceModel);

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityUser : NSObject


/// Single instance
+ (instancetype)sharedInstance;


/// uid login or register users
///
/// @param countryCode  countryCode
/// @param uid Union identify ID
/// @param password password
/// @param success Success Callback
/// @param failure Failure Callback
- (void)loginOrRegisterWithCountryCode:(NSString *)countryCode
                                   uid:(NSString *)uid
                              password:(NSString *)password
                               success:(TYSuccessID)success
                               failure:(TYFailureError)failure;

/// get user service information.
/// @param success Success Callback
/// @param failure Failure Callback
- (void)geServiceWithoutServiceCodeWithSuccess:(GetUserServiceHandler)success
                                       failure:(TYFailureError)failure;


/// get user service information
/// @param success Success Callback
/// @param failure Failure Callback
- (void)geServiceWithServiceCodeWithSuccess:(GetUserServiceHandler)success
                                    failure:(TYFailureError)failure;


/// Binding service activation code
/// @param aCode Activation code
/// @param success Success Callback
/// @param failure Failure Callback
- (void)bindServiceWithCode:(NSString *)aCode
                    success:(TYSuccessID)success
                    failure:(TYFailureError)failure;


/// Skip and using default service code.
/// @param success Success Callback
/// @param failure Failure Callback
- (void)skipBindDealerWithSuccess:(TYSuccessID)success
                          failure:(TYFailureError)failure;


/// unbind the dealer's service code
/// @param serviceCode service Code
/// @param success Success Callback
/// @param failure Failure Callback
- (void)unBindDealerWithServiceCode:(NSString *)serviceCode
                            success:(TYSuccessBOOL)success
                            failure:(TYFailureError)failure;

/// check the service code belongs to the top dealer.
/// @param success yes or not
/// @param failure failure error
- (void)checkIsBindTopServiceCodeWithSuccess:(TYSuccessBOOL)success
                                     failure:(TYFailureError)failure;


/// exchange the dealer's service code
/// @param serviceCode Activation Code
/// @param success Success Callback
/// @param failure Failure Callback
- (void)exchangeDealerWithServiceCode:(NSString *)serviceCode
                            success:(TYSuccessString)success
                            failure:(TYFailureError)failure;

/// check exchange the dealer's service code
/// @param success Success Callback
/// @param failure Failure Callback
- (void)checkExchangeDealerWithSuccess:(TYSuccessBOOL)success
                            failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
