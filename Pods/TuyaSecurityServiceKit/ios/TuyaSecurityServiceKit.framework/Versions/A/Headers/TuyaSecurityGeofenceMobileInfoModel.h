//
//  TYSecurityDeviceInfoModel.h
//  TYSecurityComponents
//
//  Created by Tuya.Inc on 2019/9/2.
//

#import <Foundation/Foundation.h>

@interface TuyaSecurityGeofenceMobileInfoModel : NSObject

/// mobile device n
@property(nonatomic, copy, nonnull) NSString *deviceId;

/// device name
@property(nonatomic, copy, nonnull) NSString *deviceName;

@end
