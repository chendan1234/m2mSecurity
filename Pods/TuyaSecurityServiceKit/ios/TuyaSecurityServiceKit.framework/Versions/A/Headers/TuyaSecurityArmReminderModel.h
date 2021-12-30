//
//  TYArmReminderModel.h
//  TuyaSecuritySDK
//
//  Created by Tuya.Inc on 2019/12/18.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSInteger, TYArmReminderType) {
    TYArmReminderTypeStay = 1,//stay
    TYArmReminderTypeAway = 2//away
};

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityArmReminderModel : NSObject

/// Home ID
@property(nonatomic, copy) NSString *homeId;

/// Arm Reminder Type
@property(nonatomic, assign) TYArmReminderType type;

///  Status(Open or Close)
@property(nonatomic, assign) BOOL enable;
@property(nonatomic, copy) NSString *checkTime;
@property(nonatomic, copy) NSString *title;
@property(nonatomic, copy) NSString *subTitle;
@property(nonatomic, assign) BOOL on;
@property(nonatomic, assign) CGFloat rowHeight;

@end

NS_ASSUME_NONNULL_END
