//
//  ResultItem.h
//  SnapDragon
//
//  Created by Sveinbjorn Thordarson on 1/29/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sys/stat.h>

@interface ResultItem : NSObject
{
    struct stat             statInfo;
    BOOL                    statLoaded;
    NSMutableDictionary     *attr;
}
- (id)init;
- (id)initWithPath: (NSString *)path;
- (void)dealloc;
+ (ResultItem *)itemWithPath: (NSString *)path;
- (void)setAttr: (id)obj forKey: (NSString *)key;
- (id)attr: (NSString *)key;
- (BOOL)hasAttr: (NSString *)theAttribute;
- (id)calcAttr: (NSString *)theAttribute;
- (NSString *)path;
- (void)_stat;
- (NSString *)description;

@end