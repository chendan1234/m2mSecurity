//
//  TYOpenedGeoMemberModel.h
//  BlocksKit
//
//  Created by Tuya.Inc on 2019/9/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityGeofenceMemberModel : NSObject

///  User's Phone Number
@property (nonatomic, copy) NSString *mobile;

/// User's Email
@property (nonatomic, copy) NSString *email;

///  User's Nickname
@property (nonatomic, copy) NSString *nickname;

///  User's ID
@property (nonatomic, copy) NSString *uid;

///  User's name
@property (nonatomic, copy) NSString *username;

///  Mobile Phone identification ID
@property (nonatomic, copy) NSString *deviceId;

/// Whether to join in
@property (nonatomic, assign) NSInteger isEffective;

/// User‘s head address
@property (nonatomic, copy) NSString *headerUrl;

@end

NS_ASSUME_NONNULL_END
