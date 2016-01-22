//
//  error.h
//  ipmt
//
//  Created by Thaisa Mirely
//  Copyright © 2015 tmbs. All rights reserved.
//

#ifndef IPMT_ERROR_H
#define IPMT_ERROR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

class Error
{
    
public:
    /*
      @brief: método para exibição de mensagem de erro e finalização da aplicação.
     */
    void static ShowException(const char* message)
    {
        fprintf(stdout, "%s",message);
        exit(EXIT_FAILURE);
    }
    
};
#endif /* IPMT_ERROR_H */
