//
//  TYActivityMsgModel.h
//  AFNetworking
//
//  Created by 浩天 on 2019/3/18.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger,TYActivityMsgType) {
    TYActivityMsgTypeNormal = 0,//normal message
    TYActivityMsgTypeWarning = 1//warning message
};

NS_ASSUME_NONNULL_BEGIN


@interface TuyaSecurityActivityMessageModel : NSObject

@property (nonatomic, copy) NSString *msgId;
@property (nonatomic, copy) NSString *msgTypeContent;
@property (nonatomic, copy) NSString *msgContent;

@property (nonatomic, assign) NSTimeInterval gmtCreate;
@property (nonatomic, copy) NSString *icon;
@property (nonatomic, copy) NSString *msgSrcId;
@property (nonatomic, copy) NSString *cameraDevId;
@property (nonatomic, copy) NSString *deviceId;
@property (nonatomic, copy) NSString *attachPics;
@property (nonatomic, copy) NSString *actionURL;
@property (nonatomic, copy) NSString *dateTime;
@property (nonatomic, copy) NSString *locationId;
@property (nonatomic, copy) NSString *msgTitle;
@property (nonatomic, copy) NSString *productId;
@property (nonatomic, copy) NSString *productType;
@property (nonatomic, copy) NSString *deviceName;

@property(nonatomic, assign) NSInteger msgType;

@property (nonatomic, assign) TYActivityMsgType level;
@property (nonatomic, assign) NSInteger hasVedio;
@property (nonatomic, assign) NSInteger readStatus;
@property (nonatomic, assign) NSInteger isAlarm;
@property (nonatomic, assign) NSInteger state;
@property (nonatomic, assign) NSInteger msgCategory;
@property (nonatomic, assign) NSInteger attachType;//(1:pic、2:video)
@property (nonatomic, assign) BOOL favorite;


@property (nonatomic, assign) BOOL selected;
@property (nonatomic, copy) NSString *p_string;

@end

NS_ASSUME_NONNULL_END
