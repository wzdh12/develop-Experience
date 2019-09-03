//
//  WZMacroDefinition.h.h
//  test
//
//  Created by twelve on 2019/9/3.
//  Copyright © 2019年 十二. All rights reserved.
//

#ifndef WZMacroDefinition_h_h
#define WZMacroDefinition_h_h

//1.屏幕的宽高
#define kSCREEN_WIDTH   [UIScreen mainScreen].bounds.size.width
#define kSCREENH_HEIGHT [UIScreen mainScreen].bounds.size.height
#define kSCREEN_BOUNDS  [UIScreen mainScreen].bounds


//2.设置随机颜色
#define kRandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]
//  设置RGB颜色
#define kRGBColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
//  设置RGBA颜色
#define kRGBAColor(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(r)/255.0 blue:(r)/255.0 alpha:a]
//  clear背景颜色
#define kClearColor [UIColor clearColor]


//3.自定义高效率的 NSLog
#ifdef DEBUG
#define KLog(...) NSLog(@"%s 第%d行 \n %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])
#else
#define KLog(...)
#endif


//4.判断机型相关
/*****************************************************************************/

//判断是否为iPhone
#define K_IS_IPHONE ([[[UIDevice currentDevice] model] isEqualToString:@"iPhone"])
//判断是否是ipad
#define IS_IPAD ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)
//判断iPhoneX
#define K_IS_IPHONE_X ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) && !IS_IPAD : NO)
//判断iPHoneXr
#define K_IS_IPHONE_Xr ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size) && !IS_IPAD : NO)
//判断iPhoneXs
#define K_IS_IPHONE_Xs ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) && !IS_IPAD : NO)
//判断iPhoneXs Max
#define K_IS_IPHONE_Xs_Max ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size) && !IS_IPAD : NO)

//根据机型 设置StatusBar的高度
#define K_Height_StatusBar ((K_IS_IPHONE_X==YES || K_IS_IPHONE_Xr ==YES || K_IS_IPHONE_Xs== YES || K_IS_IPHONE_Xs_Max== YES) ? 44.0 : 20.0)
#define K_TopBarHeight     ((K_IS_IPHONE_X==YES || K_IS_IPHONE_Xr ==YES || K_IS_IPHONE_Xs== YES || K_IS_IPHONE_Xs_Max== YES) ? 88.0 : 64.0)
#define K_TabBarHeight     ((K_IS_IPHONE_X==YES || K_IS_IPHONE_Xr ==YES || K_IS_IPHONE_Xs== YES || K_IS_IPHONE_Xs_Max== YES) ? 83.0 : 49.0)

/*****************************************************************************/


//5.存储对象
#define kUserDefaultSetObjectForKey(__VALUE__,__KEY__) \
{\
[[NSUserDefaults standardUserDefaults] setObject:__VALUE__ forKey:__KEY__];\
[[NSUserDefaults standardUserDefaults] synchronize];\
}
//获得存储的对象
#define kUserDefaultObjectForKey(__KEY__)  [[NSUserDefaults standardUserDefaults] objectForKey:__KEY__]

//删除对象
#define kUserDefaultRemoveObjectForKey(__KEY__) \
{\
[[NSUserDefaults standardUserDefaults] removeObjectForKey:__KEY__];\
[[NSUserDefaults standardUserDefaults] synchronize];\
}

//6.获取通知中心
#define kNotificationCenter [NSNotificationCenter defaultCenter]

//7.沙盒路径
#define kPATH_FOR_CACHE    NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES)[0]
#define kPATH_FOR_DOC      NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)[0]
#define kFILE_PATH_AT_CACHE(fileName)    [PATH_FOR_CACHE stringByAppendingPathComponent:fileName]
#define kFILE_PATH_AT_DOC(fileName)      [PATH_FOR_DOC stringByAppendingPathComponent:fileName]

#endif /* WZMacroDefinition_h_h */
