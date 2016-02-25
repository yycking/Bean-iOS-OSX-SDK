#import <Foundation/Foundation.h>
#import <XCTest/XCTest.h>

/**
 *  BeanContainers are used to manage the state of a physical Bean under test. They simplify test logic by stripping
 *  CoreBluetooth idiosyncrasies from the tests.
 */
@interface BeanContainer : NSObject

/**
 *  Construct a BeanContainer.
 *
 *  To start using a BeanContainer, pass in the XCTestCase that will use the Bean container and the name prefix to use
 *  when discovering Beans that are ready for testing. BeanContainer will begin discovery and return an instance of
 *  itself once a Bean with the right prefix has been discovered.
 *
 *  @param testCase The test case associated with this BeanContainer
 *  @param prefix Beans that begin with this prefix will be selected for testing
 */
+ (BeanContainer *)containerWithTestCase:(XCTestCase *)testCase andBeanNamePrefix:(NSString *)prefix;
/**
 *  Initialize a BeanContainer.
 *
 *  To start using a BeanContainer, pass in the XCTestCase that will use the Bean container and the name prefix to use
 *  when discovering Beans that are ready for testing. BeanContainer will begin discovery and return an instance of
 *  itself once a Bean with the right prefix has been discovered.
 *
 *  @param testCase The test case associated with this BeanContainer
 *  @param prefix Beans that begin with this prefix will be selected for testing
 */
- (instancetype)initWithTestCase:(XCTestCase *)testCase andBeanNamePrefix:(NSString *)prefix;

/**
 *  Connect to the Bean under test.
 *  @return YES if connect succeeded
 */
- (BOOL)connect;
/**
 *  Disconnect from the Bean under test.
 *  @return YES if disconnect succeeded
 */
- (BOOL)disconnect;

/**
 *  Set Bean's LED to a color, verify the LED was set to that color, then set the LED to black.
 *  @param color The color to set Bean's LED to
 *  @return YES if color was set successfully
 */
- (BOOL)blinkWithColor:(NSColor *)color;

@end
