//
//  error.h
//  ipmt
//
//  Created by Thaisa Mirely
//  Copyright © 2015 tmbs. All rights reserved.
//

#ifndef IPMT_ERROR_H
#define IPMT_ERROR_H

void static ShowException(const char * message)
{
    fprintf(stdout, message);
    exit(EXIT_FAILURE);
}

#endif /* IPMT_ERROR_H */
