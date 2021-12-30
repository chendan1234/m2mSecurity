//
//  TuyaSecurityBridge.h
//  AFNetworking
//
//  Created by Tuya.Inc on 2021/8/10.
//

#import <Foundation/Foundation.h>
#import <TuyaSmartUtil/TuyaSmartUtil.h>


@protocol TuyaSecurityBridgeProcotol <NSObject>

@optional

- (void)homeInitializationWithHomeId:(long long)homeId
                               extra:(NSString * _Nullable)extra
                             success:(TYSuccessBOOL _Nullable )success
                             failure:(TYFailureError _Nullable )failure;

@end


NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityBridge : NSObject


/// single instance;
+ (instancetype)sharedInstance;

/// User information is initialized. Call it after login.
///
/// @param success callback for successful request.
/// @param failure callback for failed request.
- (void)initWithSuccess:(TYSuccessBOOL)success
                failure:(TYFailureError)failure;


/// Family information initialization. Call it after create home or use security capabilities.
///
/// @param homeId homeId
/// @param extra Additional parameters(Can be null)
/// @param success callback for successful request.
/// @param failure callback for failed request.
- (void)initWithHomeId:(long long)homeId
                 extra:(NSString * _Nullable)extra
               success:(TYSuccessBOOL)success
               failure:(TYFailureError)failure;


@end

NS_ASSUME_NONNULL_END
