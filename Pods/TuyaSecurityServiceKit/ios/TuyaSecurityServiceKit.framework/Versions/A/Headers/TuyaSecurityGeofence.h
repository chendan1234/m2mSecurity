//
//  TuyaSecurityGeofence.h
//  BlocksKit
//
//  Created by Tuya.Inc on 2020/5/12.
//

#import <Foundation/Foundation.h>
#import <TuyaSmartBaseKit/TuyaSmartBaseKit.h>
#import <TuyaSmartUtil/TuyaSmartUtil.h>


@class TuyaSecurityGeofenceMobileInfoModel;
@class TuyaSecurityGeofenceCommonlyUsedMobileModel;
@class TuyaSecurityGeofenceMemberModel;
@class TuyaSecurityGeofenceRegionDataModel;
@class TuyaSecurityGeofenceRegionRecordModel;


typedef void(^GeofenceMobileList)(NSArray<TuyaSecurityGeofenceCommonlyUsedMobileModel *> * _Nullable mobileList);


typedef void(^GeofenceMemberList)(NSArray<TuyaSecurityGeofenceMemberModel *> * _Nullable memberList);


typedef void(^GeofenceRegionData)(TuyaSecurityGeofenceRegionDataModel * _Nullable dataModel);


typedef void(^AllHomeGeofenceList)(NSArray<TuyaSecurityGeofenceRegionDataModel *> * _Nullable geofenceList);


NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityGeofence : NSObject

/// singleInstance
+ (instancetype)sharedInstance;


/// Upload mobile device information
///
/// @param homeId Home ID
/// @param deviceModel Mobile phone information
/// @param success Success Callback
/// @param failure Failure Callback
- (void)uploadMobileInfo:(long long)homeId
             deviceModel:(TuyaSecurityGeofenceMobileInfoModel *)deviceModel
                 success:(TYSuccessDict)success
                 failure:(TYFailureError)failure;


/// Query the list of devices logged into the current home
///
/// @param homeId Home ID
/// @param success Success Callback
/// @param failure Failure Callback
- (void)getMobileList:(long long)homeId
              success:(GeofenceMobileList)success
              failure:(TYFailureError)failure;

/// Set up commonly used mobile phone
///
/// @param homeId  Home ID
/// @param deviceId  Device ID
/// @param success  Success Callback
/// @param failure  Failure Callback
- (void)setCommonlyUsedMobile:(long long)homeId
                     deviceId:(NSString *)deviceId
                      success:(TYSuccessBOOL)success
                      failure:(TYFailureError)failure;

/// Delete user's phone
///
/// @param homeId  Home ID
/// @param deviceId  Device ID
/// @param success  Success Callback
/// @param failure  Failure Callback
- (void)deleteMobile:(long long)homeId
            deviceId:(NSString *)deviceId
             success:(TYSuccessBOOL)success
             failure:(TYFailureError)failure;


/// Get the status of personal geographic fence service
///
/// @param homeId Home ID
/// @param success Success Callback
/// @param failure Failure Callback
- (void)getGeoServiceStatus:(long long)homeId
                    success:(TYSuccessBOOL)success
                    failure:(TYFailureError)failure;

/// Toggle individual geographic fence service status
///
/// @param homeId  Home ID
/// @param geoStatus  Geofence status
/// @param success  Success Callback
/// @param failure  Failure Callback
- (void)switchGeoService:(long long)homeId
               geoStatus:(BOOL)geoStatus
                 success:(TYSuccessBOOL)success
                 failure:(TYFailureError)failure;


/// Gets the on-off status of the home geographic fence
///
/// @param homeId  Home ID
/// @param success  Success Callback
/// @param failure  Failure Callback
- (void)getGeoFenceStatus:(long long)homeId
                  success:(TYSuccessBOOL)success
                  failure:(TYFailureError)failure;


/// Switch the home geographic fence switch
///
/// @param homeId  Home ID
/// @param fenceStatus geo fence status
/// @param success Success Callback
/// @param failure Failure Callback
- (void)switchGeoFence:(long long)homeId
         fenceStatus:(BOOL)fenceStatus
               success:(TYSuccessBOOL)success
               failure:(TYFailureError)failure;


/// Search for family members who can participate in the family geographic fence
///
/// @param homeId  Home ID
/// @param success Success Callback
/// @param failure  Failure Callback
- (void)getGeoFenceMemberList:(long long)homeId
                      success:(GeofenceMemberList)success
                      failure:(TYFailureError)failure;


/// For details of geographical fencing
///
/// @param homeId  Home ID
/// @param success Success Callback
/// @param failure Failure Callback
- (void)getHomeGeoFencingData:(long long)homeId
                      success:(GeofenceRegionData)success
                      failure:(TYFailureError)failure;


/// Inquire the home and information of the geographical fence opened under the current equipment
///
/// @param homeId  Home ID
/// @param deviceId  Local device Unique identification ID
/// @param success  Success Callback
/// @param failure  Failure Callback
- (void)getAllHomeGeoFence:(long long)homeId
                  deviceId:(NSString *)deviceId
                   success:(AllHomeGeofenceList)success
                   failure:(TYFailureError)failure;


/// Save the information from geofence
///
/// @param homeId  Home ID
/// @param recordModel  Geofence information
/// @param success  Success Callback
/// @param failure  Failure Callback
- (void)recordInitialDeviceStatus:(long long)homeId
                      recordModel:(TuyaSecurityGeofenceRegionRecordModel *)recordModel
                          success:(TYSuccessBOOL)success
                          failure:(TYFailureError)failure;


/// The phone leaves or enters a geologically fenced area
///
/// @param homeId  Home ID
/// @param geofenceHomeId  The homeId that triggered the geographic fence
/// @param deviceId  Unique identification of mobile phone
/// @param isLeaving  Leave home or not
/// @param success  Success Callback
/// @param failure  Failure Callback
- (void)processMobileInfo:(long long)homeId
           geofenceHomeId:(long long)geofenceHomeId
                 deviceId:(NSString *)deviceId
                 isLeving:(BOOL)isLeaving
                  success:(TYSuccessBOOL)success
                  failure:(TYFailureError)failure;


@end

NS_ASSUME_NONNULL_END
