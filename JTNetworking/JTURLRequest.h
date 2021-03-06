//
//  JTURLRequest.h
//  DiscuzMobile
//
//  Created by 张积涛 on 2018/2/2.
//  Copyright © 2018年 com.comzenz-service. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JTRequestConst.h"
@class JTUploadData;

@interface JTURLRequest : NSObject

@property (nonatomic, assign) JTLoadType loadType;

@property (nonatomic, assign) BOOL isCache;
/**
 *  用于标识不同类型的request
 */
@property (nonatomic, assign) JTMethodType methodType;
/**
 *  请求参数的类型
 */
@property (nonatomic, assign) JTRequestSerializerType requestSerializerType;

/**
 *  接口(请求地址)
 */
@property (nonatomic,copy) NSString * _Nonnull urlString;

/**
 *  提供给外部配置参数使用，get、post等的参数（如果是post请求，如果还需要传入get参数，用getParam,就不需拼接）
 */
@property (nonatomic,strong) id _Nonnull parameters;

/**
 *  post请求的时候备用，传入需要拼接的参数
 */
@property (nonatomic,strong) id _Nonnull getParam;

/**
 *  为上传请求提供数据
 */
@property (nonatomic, strong, nullable) NSMutableArray<JTUploadData *> *uploadDatas;

/**
 *  设置超时时间  默认15秒
 *   The timeout interval, in seconds, for created requests. The default timeout interval is 15 seconds.
 */
@property (nonatomic, assign) NSTimeInterval timeoutInterval;

/**
 *  存储路径 只有下载方法有用
 */
@property (nonatomic,copy,nullable) NSString *downloadSavePath;

/**
 *  用于维护 请求头的request对象
 */
@property ( nonatomic, strong) NSMutableDictionary * _Nonnull mutableHTTPRequestHeaders;

/**
 *  添加请求头
 *
 *  @param value value
 *  @param field field
 */
- (void)setValue:(NSString *_Nonnull)value forHeaderField:(NSString *_Nonnull)field;

/**
 *
 *  @param key request 对象
 *
 *  @return request 对象
 */
- (NSString *_Nonnull)objectHeaderForKey:(NSString *_Nonnull)key;

/**
 *  删除请求头的key
 *
 *  @param key key
 */
- (void)removeHeaderForkey:(NSString *_Nonnull)key;

//============================================================
- (void)addFormDataWithName:(NSString *_Nonnull)name fileData:(NSData *_Nonnull)fileData;
- (void)addFormDataWithName:(NSString *_Nonnull)name fileName:(NSString *_Nonnull)fileName mimeType:(NSString *_Nonnull)mimeType fileData:(NSData *_Nonnull)fileData;
- (void)addFormDataWithName:(NSString *_Nonnull)name fileURL:(NSURL *_Nonnull)fileURL;
- (void)addFormDataWithName:(NSString *_Nonnull)name fileName:(NSString *_Nonnull)fileName mimeType:(NSString *_Nonnull)mimeType fileURL:(NSURL *_Nonnull)fileURL;

@end

@interface JTUploadData : NSObject

/**
 文件对应服务器上的字段
 */
@property (nonatomic, copy) NSString * _Nonnull name;

/**
 文件名
 */
@property (nonatomic, copy, nullable) NSString *fileName;

/**
 图片文件的类型,例:png、jpeg....
 */
@property (nonatomic, copy, nullable) NSString *mimeType;

/**
 The data to be encoded and appended to the form data, and it is prior than `fileURL`.
 */
@property (nonatomic, strong, nullable) NSData *fileData;

/**
 The URL corresponding to the file whose content will be appended to the form, BUT, when the `fileData` is assigned，the `fileURL` will be ignored.
 */
@property (nonatomic, strong, nullable) NSURL *fileURL;

//注意:“fileData”和“fileURL”中的任何一个都不应该是“nil”，“fileName”和“mimeType”都必须是“nil”，或者同时被分配，

+ (instancetype _Nonnull )formDataWithName:(NSString *_Nonnull)name fileData:(NSData *_Nonnull)fileData;
+ (instancetype _Nonnull )formDataWithName:(NSString *_Nonnull)name fileName:(NSString *_Nonnull)fileName mimeType:(NSString *_Nonnull)mimeType fileData:(NSData *_Nonnull)fileData;
+ (instancetype _Nonnull )formDataWithName:(NSString *_Nonnull)name fileURL:(NSURL *_Nonnull)fileURL;
+ (instancetype _Nonnull )formDataWithName:(NSString *_Nonnull)name fileName:(NSString *_Nonnull)fileName mimeType:(NSString *_Nonnull)mimeType fileURL:(NSURL *_Nonnull)fileURL;

@end
