//
//  TYGeoDeviceModel.h
//  TYSecurityComponents
//
//  Created by Tuya.Inc on 2019/9/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityGeofenceCommonlyUsedMobileModel : NSObject

/// User ID
@property(nonatomic, copy) NSString *uid;

///  User Name
@property(nonatomic, copy) NSString *name;

///   User Mobile Phone's unique identification ID
@property(nonatomic, copy) NSString *uuid;

///  Active Mobile Phone
@property(nonatomic, strong) NSNumber *active;

///  The last time the user logged in
@property(nonatomic, assign) NSTimeInterval lastLoginTime;


@end

NS_ASSUME_NONNULL_END
