
//1.要在工程中打开下面内容
Xcode -> [Project Name] -> Targets -> [Target Name] -> Capabilities -> Access WiFi Information -> ON
// 2.导入头文件
#import <SystemConfiguration/CaptiveNetwork.h>

//3.调用方法
+ (NSString *)wifiSSID {
    
    NSString *ssid = nil;
    NSArray *ifs = (__bridge_transfer id)CNCopySupportedInterfaces();
    for (NSString *ifnam in ifs) {
        NSDictionary *info = (__bridge_transfer id)CNCopyCurrentNetworkInfo((__bridge CFStringRef)ifnam);
        if (info[@"SSID"]) {
            ssid = info[@"SSID"];
            KNSLog(@"%@",info);
        }
    }
    return ssid;
}
