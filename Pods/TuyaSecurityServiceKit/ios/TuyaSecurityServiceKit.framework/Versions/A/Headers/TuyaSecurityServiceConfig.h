//
//  TuyaSecurityServiceConfig.h
//  BlocksKit
//
//  Created by Tuya.Inc on 2020/5/7.
//

#import <Foundation/Foundation.h>
#import <TuyaSmartBaseKit/TuyaSmartBaseKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityServiceConfig : NSObject

/// singleInstance
+ (instancetype)sharedInstance;

/// Get service configuration
///
///Callback，service_url(Service plan URL)  help_url(Help Page URL)
/// @param failure Failure Callback
- (void)getServiceConfigWithSuccess:(TYSuccessDict)success
                            failure:(TYFailureError)failure  __deprecated_msg("Use - [TuyaSecurityServiceConfig getSecurityConfigWithSuccess:failure:] instead");

/// Get All Smart Security App configuration
/// hosting_service_url hosting service protocol
/// base_cloud_storage_url base storage protocol
/// @param failure 失败回调 / Failure Callback
- (void)getSecurityConfigWithSuccess:(nonnull TYSuccessDict)success
                             failure:(TYFailureError)failure;

/// Configuration based on the get URL of the userId
///
- (NSDictionary *)getServiceConfigURLMapFromCache;

@end

NS_ASSUME_NONNULL_END
