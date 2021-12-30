//
//  TuyaSecurityMessageManager.h
//  TuyaSecurityMessageKit
//
//  Created by Tuya.Inc on 2020/5/12.
//

#import <Foundation/Foundation.h>
#import "TuyaSecurityMessageKitDefinition.h"
#import "TuyaSecurityActivityMessageModel.h"
#import "TuyaSecurityNotificationCategoryListModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^TYSecurityMessageListBlcok)(NSArray<TuyaSecurityActivityMessageModel *> *dataArray);
typedef void(^NotificationCategoryListBlock)(NSArray<TuyaSecurityNotificationCategoryListModel *> *dataArray);

@interface TuyaSecurityMessageManager : NSObject

+ (instancetype)sharedInstance;

/// Get Message List
///
/// @param homeId home id
/// @param messageType message type
/// @param isBatchesCollect batchese collect
/// @param startDate start date
/// @param endDate end date
/// @param offset offset
/// @param success success
/// @param failure failure
- (void)getCenterMessagesWithHomeId:(long long)homeId
                        messageType:(TYSecurityArmedMsgType)messageType
                   isBatchesCollect:(BOOL)isBatchesCollect
                          startDate:(nullable NSString *)startDate
                            endDate:(nullable NSString *)endDate
                             offset:(NSInteger)offset
                            success:(nullable TYSecurityMessageListBlcok)success
                            failure:(nullable void(^)(NSError *error))failure;

/**
 update favorite device state

 @param homeId homeId
 @param messageIds messge Id
 @param favoriteState state
 @param success success
 @param failure failure
 */
- (void)updateFavoriteMessageStateWithHomeId:(long long) homeId
                                  messageIds:(NSString *)messageIds
                               favoriteState:(TYSecurityMessageFavoriteState)favoriteState
                                     success:(nullable void(^)(BOOL success))success
                                     failure:(nullable void(^)(NSError *error))failure;

/**
 batch delete message

 @param homeId location id
 @param messageId message ids
 @param messageType messagetype: 1-CAMERA,2-SECURITY,3-GENERAL
 @param success success
 @param failure failure
 */
- (void)removeCenterMessagesWithHomeId:(long long)homeId
                             messageId:(NSString *)messageId
                           withMsgType:(NSString *)messageType
                               success:(nullable void(^)(BOOL success))success
                               failure:(nullable void(^)(NSError *error))failure;

/// update message read state
/// @param homeId loaction id
/// @param messageId message id
/// @param messageType messagetype: 1-CAMERA,2-SECURITY,3-GENERAL
/// @param success success
/// @param failure failure
- (void)updateMessageStateWithHomeId:(long long)homeId
                           messageId:(NSString *)messageId
                         messageType:(NSString *)messageType
                             success:(nullable void(^)(BOOL success))success
                             failure:(nullable void(^)(NSError *error))failure;


/// get default notification config information
/// @param homeId location id
/// @param success success
/// @param failure failure
- (void)getNotificationCategoryListWithHomeId:(long long)homeId
                                      success:(nullable void(^)(NSDictionary *resultDictionary))success
                                      failure:(nullable void(^)(NSError *error))failure;

/// switch notificaiton state
/// @param homeId location id
/// @param bizId notificatin category id
/// @param bizValue switch state
/// @param success success
/// @param failure failure
- (void)updateNotificationCategoryWithHomeId:(long long)homeId
                                       bizId:(NSString *)bizId
                                    bizValue:(BOOL)bizValue
                                     success:(nullable void(^)(BOOL success))success
                                     failure:(nullable void(^)(NSError *error))failure;

/// get notification category default config information
/// @param homeId locaton id
/// @param bizId notification category: push,email,sms,voicecall
/// @param bizKey category type（alarmAlerts, cameraAlerts, homeAutomationAlerts, bulletins）
/// @param success success
/// @param failure  failure
- (void)getNotificationConfigListWithHomeId:(long long)homeId
                                      bizId:(NSString *)bizId
                                     bizKey:(NSString *)bizKey
                                    success:(nullable NotificationCategoryListBlock)success
                                    failure:(nullable void(^)(NSError *error))failure;

/// switch notificatoin category state
/// @param homeId location id
/// @param bizId notification category: push,email,sms,voicecall
/// @param messageType notification category state
/// @param bizValue switch state
/// @param success success
/// @param failure failure
- (void)updateNotificationConfigWithHomeId:(long long)homeId
                                     bizId:(NSString *)bizId
                               messageType:(NSInteger)messageType
                                  bizValue:(BOOL)bizValue
                                   success:(nullable void(^)(BOOL success))success
                                   failure:(nullable void(^)(NSError *error))failure;

/// reset notification configration
/// @param homeId location id
/// @param bizId notification category: push,email,sms,voicecall
/// @param bizKey  notification category type（alarmAlerts, cameraAlerts, homeAutomationAlerts, bulletins）
/// @param success success
/// @param failure failure
- (void)resetNotificationConfigDefaultWithHomeId:(long long)homeId
                                           bizId:(NSString *)bizId
                                          bizKey:(NSString *)bizKey
                                         success:(nullable void(^)(BOOL success))success
                                         failure:(nullable void(^)(NSError *error))failure;

///get push notification voice、shake state
/// @param homeId location id
/// @param bizId notification category id (push)
/// @param bizKey notification category type (customizeConfig)
/// @param success success
/// @param failure failure
- (void)getNotDisturbConfigListWithHomeId:(long long)homeId
                                    bizId:(NSString *)bizId
                                   bizKey:(NSString *)bizKey
                                  success:(nullable NotificationCategoryListBlock)success
                                  failure:(nullable void(^)(NSError *error))failure;

/// update not disturb time
/// @param homeId location id
/// @param bizId notification category id (push)
/// @param targetId Id
/// @param startTime star time
/// @param endTime end time
/// @param success success
/// @param failure failure
 - (void)updateNotDisturbTimeWithHomeId:(long long)homeId
                                  bizId:(NSString *)bizId
                               targetId:(NSString *)targetId
                              startTime:(NSString *)startTime
                                endTime:(NSString *)endTime
                                success:(nullable void(^)(NSString *result))success
                                failure:(nullable void(^)(NSError *error))failure;
@end

NS_ASSUME_NONNULL_END
