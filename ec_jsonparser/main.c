//
//  main.c
//  ec_jsonparser
//
//  Created by LongFu on 2017/10/18.
//  Copyright © 2017年 Freelancer. All rights reserved.
//
//
#include <stdio.h>
#include "jsontree.h"
#include "jsonparse.h"


char json[] = "{\"name\":\"long\",\"user\":12}";
int main(int argc, const char * argv[]) {
    struct jsonparse_state state1;
    char buf[16] = { 0 };
    printf("%s\n",json);
    jsonparse_setup((struct jsonparse_state *)&state1, json, (int)strlen(json));
    int type;
    while ((type = jsonparse_next(&state1)) != 0) {
        if (type == JSON_TYPE_PAIR_NAME)
        {
            if (jsonparse_strcmp_value(&state1, "name") == 0)
            {
                char buf[16] = { 0 };
                jsonparse_next(&state1);
                jsonparse_next(&state1);
                jsonparse_copy_value(&state1, buf, sizeof(buf));
                printf("buff %s\n",buf);
            }
            
            if (jsonparse_strcmp_value(&state1, "user") == 0)
            {
                char buf[4]= { 0 };
                int s;
                jsonparse_next(&state1);
                jsonparse_next(&state1);
//                jsonparse_next(&state1);
//                jsonparse_copy_value(&state1, buf, sizeof(buf));
                s = jsonparse_get_value_as_int(&state1);
                printf(" ---- == = %d\n",s);
            }
        }
    }
    
    
//    int r = jsonparse_strcmp_value(&state1, "user");
//    printf(" -- r -- %d\n",r);
//    jsonparse_next(&state1);
//    jsonparse_next(&state1);
//    jsonparse_copy_value(&state1, buf, sizeof(buf));
//    printf("%s\n",buf);
    return 0;
}

