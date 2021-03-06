//
//  BEProperty.h
//  XLibEditor
//
//  Created by Wing Xu on 13-3-13.
/*
 
 Copyright (c) 2015, Wing Xu
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 
 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 
 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 */
enum{
    kInteger,
    kFloat,
    kKeyword,
    kString,
    kPhoto,
    kSelection,
    kReference,
    kClassify,
    kList,
    kListItem,
    kCollection
};

enum{
    kTemplateMode,
    kInstanceMode
};

#import <Foundation/Foundation.h>

#import "BEResourceController.h"

@interface BEProperty : NSObject

@property (nonatomic) NSString *name;

@property (nonatomic) NSNumber *propertyType;

@property (nonatomic) NSString *value;
@property (nonatomic) NSString *photoPath;

@property (nonatomic) NSNumber *numberValue;

@property (nonatomic) NSNumber *max, *min;

@property (nonatomic) NSString *referencePath;

@property (nonatomic) BEProperty *propertyTemplate;

@property NSInteger mode;

@property (nonatomic) NSNumber *allowedChildrenReference;

@property (nonatomic) NSMutableArray *children, *selection;

@property (nonatomic) id parentProperty;

@property (nonatomic) BOOL valueEnabled,editEnabled,rangeEnabled,subEnabled,selectionEnabled,textEnabled,photoEnabled,addEnabled,removeEnabled;

@property (nonatomic) id <BEResourceController> resourceController;

- (NSString *)fullPath;

- (NSMutableDictionary *)archiveDictionary;

- (void)loadArchive:(NSDictionary *)propertyArchive;

- (BEProperty*)instanceCopy;

+ (BOOL)name:(NSString *)name existInArray:(NSArray *)array;

+ (NSString *) generateNameWithPrefix:(NSString *)prefix inArray:(NSMutableArray *)array;

- (void)renameSubPropertiesWithPrefix:(NSString*)prefix;

- (void)clearReference;

- (void)addListItem;

@end
