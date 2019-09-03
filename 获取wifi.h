
// 导入头文件
#import <SystemConfiguration/CaptiveNetwork.h>


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
