/*
 *  StringUtils.h
 *  Apto
 *
 *  Created by David on 3/15/11.
 *  Copyright 2011 David Michael Bryson. All rights reserved.
 *  http://programerror.com/software/apto
 *
 *  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 *  following conditions are met:
 *  
 *  1.  Redistributions of source code must retain the above copyright notice, this list of conditions and the
 *      following disclaimer.
 *  2.  Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *      following disclaimer in the documentation and/or other materials provided with the distribution.
 *  3.  Neither the name of David Michael Bryson, nor the names of contributors may be used to endorse or promote
 *      products derived from this software without specific prior written permission.
 *  
 *  THIS SOFTWARE IS PROVIDED BY DAVID MICHAEL BRYSON AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL DAVID MICHAEL BRYSON OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 *  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  Authors: David M. Bryson <david@programerror.com>
 *
 */

#ifndef AptoCoreStringUtils_h
#define AptoCoreStringUtils_h

#include <cstdlib>

namespace Apto {

  class StrAs
  {
  private:
    const char* m_str;
    
    StrAs(); // @not_implemented
    
  public:
    inline explicit StrAs(const char* str) : m_str(str) { ; }
    template <class T> explicit StrAs(const T& str) : m_str(str) { ; }
    
    inline operator bool() const;
    
    inline operator int() const { return strtol(m_str, NULL, 0); }
    inline operator long() const { return strtol(m_str, NULL, 0); }
    inline operator long long() const { return strtoll(m_str, NULL, 0); }
    inline operator unsigned int() const { return strtoul(m_str, NULL, 0); }
    inline operator unsigned long() const { return strtoul(m_str, NULL, 0); }
    inline operator unsigned long long() const { return strtoull(m_str, NULL, 0); }
      
    inline operator float() const { return strtof(m_str, NULL); }
    inline operator double() const { return strtod(m_str, NULL); }
    inline operator long double() const { return strtold(m_str, NULL); }
    
    inline operator const char*() const { return m_str; }
  };
  
  inline StrAs::operator bool() const
  {
    const int size = strlen(m_str);
    if (size == 1) {
      if (m_str[0] == '1' || m_str[0] == 'T' || m_str[0] == 't') return true;
      else return false;
    }
    if (size == 4 && (m_str[0] == 'T' || m_str[0] == 't') && (m_str[1] == 'R' || m_str[1] == 'r') &&
                     (m_str[2] == 'U' || m_str[2] == 'u') && (m_str[3] == 'E' || m_str[3] == 'e')) {
      return true;
    }
    return false;
  }
};

#endif