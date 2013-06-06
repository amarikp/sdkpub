/*=============================================================================
        File: barray.cpp
     Purpose:       
    Revision: $Id: barray_complex.cpp,v 1.2 2002/05/13 21:07:45 philosophil Exp $
  Created by: Philippe Lavoie          (3 Oct, 1996)
 Modified by: 

 Copyright notice:
          Copyright (C) 1996-1998 Philippe Lavoie
 
	  This library is free software; you can redistribute it and/or
	  modify it under the terms of the GNU Library General Public
	  License as published by the Free Software Foundation; either
	  version 2 of the License, or (at your option) any later version.
 
	  This library is distributed in the hope that it will be useful,
	  but WITHOUT ANY WARRANTY; without even the implied warranty of
	  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	  Library General Public License for more details.
 
	  You should have received a copy of the GNU Library General Public
	  License along with this library; if not, write to the Free
	  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
=============================================================================*/

#include "barray.cpp"

namespace PLib {

#if 0
ostream&
BasicArray<NComplex>::print(ostream& os)  const{
  const int iend = size();
  
  for (int i = 0; i < iend;  )
    {
      os << real(x[i]) << "+" << imag(x[i]) << "i" ; // << endl;
      if ( (++i % wdth) == 0 )
	os << '\n';
      else
	os << "   "; 
    }
  os << '\n' ;
  
  return os;	
}
#endif

#ifdef NO_IMPLICIT_TEMPLATES
  template class BasicArray<NComplex> ;
  template void resizeBasicArray<NComplex>(BasicArray<NComplex>&,int) ;
  template int operator!=(const BasicArray<NComplex>&,const BasicArray<NComplex>&); 
  template int operator==(const BasicArray<NComplex>&,const BasicArray<NComplex>&); 
  template istream& operator>>(istream& is, BasicArray<NComplex>& ary);
  template ostream& operator<<(ostream& os, const BasicArray<NComplex>& ary);

#endif

}

#ifdef NO_IMPLICIT_TEMPLATES
//  template double std::abs<double>(const std::complex<double> &);
//  template NComplex std::conj<double>(const NComplex&);
#endif

