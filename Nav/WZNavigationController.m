//
//  WZNavigationController.m
//  ERP管理端
//
//  Created by 十二 on 2018/1/3.
//  Copyright © 2018年 十二. All rights reserved.
//

#import "WZNavigationController.h"

@interface WZNavigationController ()<UIGestureRecognizerDelegate>

@end

@implementation WZNavigationController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationBar.translucent = NO;
    self.interactivePopGestureRecognizer.delegate = self;
    self.navigationBar.barTintColor = kNavBarColor;
    [self.navigationBar setTitleTextAttributes:@{NSForegroundColorAttributeName : [UIColor whiteColor]}];
    
}

- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)gestureRecognizer{
//    // 注意：只有非根控制器才有滑动返回功能，根控制器没有。
//    // 判断导航控制器是否只有一个子控制器，如果只有一个子控制器，肯定是根控制器
//    if (self.childViewControllers.count == 1) {
//        // 表示用户在根控制器界面，就不需要触发滑动手势，
//        return NO;
//    }
//    return YES;
    // 手势何时有效 : 当导航控制器的子控制器个数 > 1就有效
    return self.childViewControllers.count > 1;
}
-(void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated{
    if (self.viewControllers.count > 0) {
        UIButton *backButton = [UIButton buttonWithType:UIButtonTypeCustom];
        backButton.adjustsImageWhenDisabled = NO;
        [backButton setImage:[UIImage imageNamed:@"WZ返回"] forState:UIControlStateNormal];
//        [backButton setBackgroundImage:[UIImage imageNamed:@"back_black"] forState:UIControlStateNormal];
        backButton.frame = CGRectMake(0, 0, 44, 44);
        //backButton.backgroundColor = [UIColor redColor];
//        [backButton sizeToFit];
        [backButton addTarget:self action:@selector(back) forControlEvents:UIControlEventTouchUpInside];
        viewController.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc]initWithCustomView:backButton];
        
        viewController.hidesBottomBarWhenPushed = YES;
    }
    
    [super pushViewController:viewController animated:animated];
}

-(void)back{
    
    [self popViewControllerAnimated:YES];
}
//是否支持屏幕旋转
-(BOOL)shouldAutorotate{
    return [self.topViewController shouldAutorotate];
}
//你跳转（present）到这个新控制器时，按照什么方向初始化控制器
-(UIInterfaceOrientation)preferredInterfaceOrientationForPresentation{
    return [self.topViewController preferredInterfaceOrientationForPresentation];
}
//返回一个ViewController支持的方向，也就是说你返回这个方向是你屏幕启动后就保持的方向，如让他默认横屏或者竖屏
//1.仅在IOS6 以后才能用
//2.用户在每次改变屏幕转动方向的时候，会先调用shouldAutorotate，再调用它，这就说明，仅在shouldAutorotate方法返回值是YES的时候这个方法才会起作用！
//3.如果没有重写这个方法，ipad默认返回的值是UIInterfaceOrientationMaskAll ，iphone默认返回的值是UIInterfaceOrientationMaskAllButUpsideDown，也就是说默认情况下iOS是支持翻转屏幕的
-(UIInterfaceOrientationMask)supportedInterfaceOrientations{
    return   [self.topViewController supportedInterfaceOrientations];
}
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation != self.orietation);
}
@end
