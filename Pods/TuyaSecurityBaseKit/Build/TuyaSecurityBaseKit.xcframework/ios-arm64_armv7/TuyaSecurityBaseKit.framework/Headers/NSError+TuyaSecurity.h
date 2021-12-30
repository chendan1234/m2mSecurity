//
//  NSError+TuyaSecurity.h
//  TuyaSecurityBaseKit
//
//  Created by Tuya.Inc on 2021/3/9.
//

#import <Foundation/Foundation.h>
#import "TuyaSecuritySDKErrorCode.h"

#define TuyaSecError(code,msg) \
[NSError errorWithSecErrorCode:code errorMessage:msg]

#define TuyaSecErrorNotLinkService [NSError errorWithSecErrorCode:TuyaSecuritySDKErrorCodeNotLinkService]


NS_ASSUME_NONNULL_BEGIN

@interface NSError (TuyaSecurity)

@property (nonatomic, assign) TuyaSecuritySDKErrorCode tuyaSecErrorCode;

@property (nonatomic, copy) NSString *tuyaSecErrorMsg;


+ (NSError *)errorWithSecErrorCode:(TuyaSecuritySDKErrorCode)errorCode
                      errorMessage:(NSString *)errorMessage;

+ (NSError *)errorWithSecErrorCode:(TuyaSecuritySDKErrorCode)errorCode;

@end

NS_ASSUME_NONNULL_END
