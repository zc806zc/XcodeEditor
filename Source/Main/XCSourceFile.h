////////////////////////////////////////////////////////////////////////////////
//
//  EXPANZ
//  Copyright 2008-2011 EXPANZ
//  All Rights Reserved.
//
//  NOTICE: Expanz permits you to use, modify, and distribute this file
//  in accordance with the terms of the license agreement accompanying it.
//
////////////////////////////////////////////////////////////////////////////////
#import <Foundation/Foundation.h>
#import "XcodeGroupMember.h"
#import "XcodeSourceFileType.h"

@class XCProject;

/**
* Represents a file resource in an xcode project.
*/
@interface XCSourceFile : NSObject<XcodeGroupMember> {

@private
    __weak XCProject* _project;

    NSNumber* _isBuildFile;
    NSString* _buildFileKey;
    NSString* _name;
    NSString* _sourceTree;
    NSString* _key;
    XcodeSourceFileType _type;
}

@property(nonatomic, readonly) XcodeSourceFileType type;
@property(nonatomic, strong, readonly) NSString* key;
@property(nonatomic, strong, readonly) NSString* name;
@property(nonatomic, strong, readonly) NSString* sourceTree;

+ (XCSourceFile*) sourceFileWithProject:(XCProject*)project
        key:(NSString*)key
        type:(XcodeSourceFileType)type
        name:(NSString*)name
        sourceTree:(NSString*)tree;

- (id) initWithProject:(XCProject*)project
        key:(NSString*)key
        type:(XcodeSourceFileType)type
        name:(NSString*)name
        sourceTree:(NSString*)tree;

/**
* If yes, indicates the file is able to be included for compilation in an `XCTarget`.
*/
- (BOOL) isBuildFile;

- (BOOL) canBecomeBuildFile;

- (XcodeMemberType) buildPhase;

- (NSString*) buildFileKey;

/**
* Adds this file to the project as an `xcode_BuildFile`, ready to be included in targets.
*/
- (void) becomeBuildFile;

@end