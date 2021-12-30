//
//  TYEventSensorGroupModel.h
//  BlocksKit
//
//  Created by Tuya.Inc on 2019/10/23.
//

#import <Foundation/Foundation.h>
#import "TuyaSecurityEventRecordingSensorModel.h"


NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityEventSensorGroupModel : NSObject


///  Room Name
@property (nonatomic, copy) NSString *roomName;

///  Sensor List
@property (nonatomic, strong) NSArray<TuyaSecurityEventRecordingSensorModel *> *sensorDeviceList;

@end

NS_ASSUME_NONNULL_END
