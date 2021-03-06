/* --------------------------------------------------------------------
Author: Sylvain Lefebvre    sylvain.lefebvre@sophia.inria.fr

                  Simple Library for Graphics (LibSL)

This software is a computer program whose purpose is to offer a set of
tools to simplify programming real-time computer graphics applications
under OpenGL and DirectX.

This software is governed by the CeCILL-C license under French law and
abiding by the rules of distribution of free software.  You can  use, 
modify and/ or redistribute the software under the terms of the CeCILL-C
license as circulated by CEA, CNRS and INRIA at the following URL
"http://www.cecill.info". 

As a counterpart to the access to the source code and  rights to copy,
modify and redistribute granted by the license, users are provided only
with a limited warranty  and the software's author,  the holder of the
economic rights,  and the successive licensors  have only  limited
liability. 

In this respect, the user's attention is drawn to the risks associated
with loading,  using,  modifying and/or developing or reproducing the
software by the user in light of its specific status of free software,
that may mean  that it is complicated to manipulate,  and  that  also
therefore means  that it is reserved for developers  and  experienced
professionals having in-depth computer knowledge. Users are therefore
encouraged to load and test the software's suitability as regards their
requirements in conditions enabling the security of their systems and/or 
data to be ensured and,  more generally, to use and operate it in the 
same conditions as regards security. 

The fact that you are presently reading this means that you have had
knowledge of the CeCILL-C license and that you accept its terms.
-------------------------------------------------------------------- */
// ------------------------------------------------------
#include "LibSL.precompiled.h"
// ------------------------------------------------------

#include <LibSL/Geometry/Intersections/Intersection_Plane_AABox.h>
using namespace LibSL::Geometry;
using namespace LibSL::Math;

// ------------------------------------------------------

#define NAMESPACE LibSL::Geometry::Intersections

// ------------------------------------------------------

// low level routine
int plane_aabox(const v3f& normal, const v3f& vert, const v3f& maxbox);

// ------------------------------------------------------

bool NAMESPACE::Plane_AABox(const Plane<3>& p,const AABox& b)
{
  v3f ctr    = (b.minCorner() + b.maxCorner())*0.5f;
  v3f hfsz   = (b.maxCorner() - b.minCorner())*0.5f;
  v3f pt     = p.n()*p.d();
  return (plane_aabox(p.n(),pt-ctr,hfsz) != 0);
}

// ------------------------------------------------------

bool NAMESPACE::AABox_Plane(const LibSL::Geometry::AABox& b  ,const LibSL::Geometry::Plane<3>& p) 
{
  return Plane_AABox(p,b);
}

// ------------------------------------------------------
