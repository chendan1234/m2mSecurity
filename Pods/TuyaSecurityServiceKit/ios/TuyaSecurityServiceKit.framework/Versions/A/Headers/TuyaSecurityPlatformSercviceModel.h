//
//  TYSPlatformSercviceModel.h
//  TYSecurityUserCenterBizKit
//
//  Created by Tuya.Inc on 2021/4/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityPlatformSercviceModel : NSObject

/// ecommodity code, push detail page needed, eg:EC9h61pmupy12g.
@property (nonatomic, copy) NSString *ecommodityCode;

/// ecommodity name, only used by showing, eg:cloud storage.
@property (nonatomic, copy) NSString *ecommodityName;

/// service icon URL, only used by showing, eg:"https://...".
@property (nonatomic, strong) NSURL *iconURL;

/// service icon name, only supports local resource.
@property (nonatomic, copy) NSString *iconName;

/// category code, push detail page needed, eg:cloud_storage.
@property (nonatomic, copy) NSString *categoryCode;

/// service description.
@property (nonatomic, copy) NSString *serviceDesc;

@property (nonatomic, assign) NSInteger type;

@property (nonatomic, assign) NSInteger order;

@end




@interface TuyaSecurityPlatformSercviceListModel : NSObject

@property (nonatomic, copy) NSString *serviceType;

@property (nonatomic, copy) NSString *channelId;

@property (nonatomic, copy) NSString *dealerId;

@property (nonatomic, copy) NSArray<TuyaSecurityPlatformSercviceModel *> *basicEcommodityList;

@property (nonatomic, copy) NSArray<TuyaSecurityPlatformSercviceModel *> *thirdEcommodityList;

@end


NS_ASSUME_NONNULL_END
