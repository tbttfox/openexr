///////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2004, Industrial Light & Magic, a division of Lucas
// Digital Ltd. LLC
// 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
// *       Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// *       Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// *       Neither the name of Industrial Light & Magic nor the names of
// its contributors may be used to endorse or promote products derived
// from this software without specific prior written permission. 
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
///////////////////////////////////////////////////////////////////////////



#ifndef INCLUDED_IMF_OPAQUE_ATTRIBUTE_H
#define INCLUDED_IMF_OPAQUE_ATTRIBUTE_H

//
//	Copyright  (c)  2000    Industrial   Light   and   Magic.
//	All   rights   reserved.    Used   under   authorization.
//	This material contains the confidential  and  proprietary
//	information   of   Industrial   Light   and   Magic   and
//	may not be copied in whole or in part without the express
//	written   permission   of  Industrial Light  and   Magic.
//	This  copyright  notice  does  not   imply   publication.
//

//-----------------------------------------------------------------------------
//
//	class OpaqueAttribute
//
//	When an image file is read, OpqaqueAttribute objects are used
//	to hold the values of attributes whose types are not recognized
//	by the reading program.  OpaqueAttribute objects can be read
//	from an image file, copied, and written back to to another image
//	file, but their values are inaccessible.
//
//-----------------------------------------------------------------------------

#include <ImfAttribute.h>
#include <ImfArray.h>

namespace Imf {


class OpaqueAttribute: public Attribute
{
  public:

    //----------------------------
    // Constructors and destructor
    //----------------------------

    OpaqueAttribute (const char typeName[]);
    OpaqueAttribute (const OpaqueAttribute &other);
    virtual ~OpaqueAttribute ();


    //-------------------------------
    // Get this attribute's type name
    //-------------------------------

    virtual const char *	typeName () const;
    

    //------------------------------
    // Make a copy of this attribute
    //------------------------------

    virtual Attribute *		copy () const;


    //----------------
    // I/O and copying
    //----------------

    virtual void		writeValueTo (OStream &os,
					      int version) const;

    virtual void		readValueFrom (IStream &is,
					       int size,
					       int version);

    virtual void		copyValueFrom (const Attribute &other);


  private:

    Array<char>			_typeName;
    long			_dataSize;
    Array<char>			_data;
};


} // namespace Imf

// Metrowerks compiler wants the .cpp file inlined, too
#ifdef __MWERKS__
#include <ImfOpaqueAttribute.cpp>
#endif

#endif
