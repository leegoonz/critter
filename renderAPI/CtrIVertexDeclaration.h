//------------------------------------------------------------------------------------//
//                                                                                    //
//               _________        .__  __    __                                       //
//               \_   ___ \_______|__|/  |__/  |_  ___________                        //
//               /    \  \/\_  __ \  \   __\   __\/ __ \_  __ \                       //
//               \     \____|  | \/  ||  |  |  | \  ___/|  | \/                       //
//                \______  /|__|  |__||__|  |__|  \___  >__|                          //
//                       \/                           \/                              //
//                                                                                    //
//    Critter is provided under the MIT License(MIT)                                  //
//    Critter uses portions of other open source software.                            //
//    Please review the LICENSE file for further details.                             //
//                                                                                    //
//    Copyright(c) 2015 Matt Davidson                                                 //
//                                                                                    //
//    Permission is hereby granted, free of charge, to any person obtaining a copy    //
//    of this software and associated documentation files(the "Software"), to deal    //
//    in the Software without restriction, including without limitation the rights    //
//    to use, copy, modify, merge, publish, distribute, sublicense, and / or sell     //
//    copies of the Software, and to permit persons to whom the Software is           //
//    furnished to do so, subject to the following conditions :                       //
//                                                                                    //
//    1. Redistributions of source code must retain the above copyright notice,       //
//    this list of conditions and the following disclaimer.                           //
//    2. Redistributions in binary form must reproduce the above copyright notice,    //
//    this list of conditions and the following disclaimer in the                     //
//    documentation and / or other materials provided with the distribution.          //
//    3. Neither the name of the copyright holder nor the names of its                //
//    contributors may be used to endorse or promote products derived                 //
//    from this software without specific prior written permission.                   //
//                                                                                    //
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR      //
//    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,        //
//    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE      //
//    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER          //
//    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,   //
//    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN       //
//    THE SOFTWARE.                                                                   //
//                                                                                    //
//------------------------------------------------------------------------------------//
#ifndef INCLUDED_CRT_VERTEXDECLARATION_INTERFACE
#define INCLUDED_CRT_VERTEXDECLARATION_INTERFACE

#include <CtrIRenderResource.h>
#include <CtrIRenderResourceParameters.h>

namespace Ctr
{
class  IVertexDeclaration : public IRenderResource
{
  public:
    IVertexDeclaration (Ctr::IDevice* device);
    virtual ~IVertexDeclaration();

    virtual bool               initialize (const VertexDeclarationParameters*) = 0;
    virtual bool               create() = 0;
    virtual bool               free() = 0;
    virtual bool               bind() const = 0;

    virtual uint32_t           vertexStreamCount() const = 0;
    virtual unsigned int       vertexStride() const = 0;
    virtual const std::vector <VertexElement>& getDeclaration() const = 0;

    static uint32_t            elementToSize(const BYTE& type) 
    {
        switch(type)
        {
            case FLOAT1:
                return 1 * sizeof(float);
            case FLOAT2:
                return 2 * sizeof(float);
            case FLOAT3:
                return 3 * sizeof(float);
            case FLOAT4:   
                return 4 * sizeof(float);
            case UBYTE4:
                return 4 * sizeof(uint8_t);
        }
        return 0;
    }

  protected:
};

}

#endif