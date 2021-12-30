//
//  TYGeofenceRecordInfoModel.h
//  BlocksKit
//
//  Created by Tuya.Inc on 2019/9/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityGeofenceRegionRecordModel : NSObject


///  Device unique identification ID
@property(nonatomic, copy) NSString *deviceId;

///  longitude（Precision to 10 decimal places）
@property(nonatomic, copy) NSString *lon;

///  latitude Precision to 10 decimal places）
@property(nonatomic, copy) NSString *lat;

///  radius Precision to 2 decimal places）
@property(nonatomic, copy) NSString *radius;

/// Location's Name
@property(nonatomic, copy) NSString *title;

@end

NS_ASSUME_NONNULL_END
