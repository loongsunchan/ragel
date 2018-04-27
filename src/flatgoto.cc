/*
 * Copyright 2018-2018 Adrian Thurston <thurston@colm.net>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "flatgoto.h"


void FlatGoto::VARS()
{
	klen.reference();
	ckeys.reference();
	trans.reference();
	cond.reference();
	keys.reference();
	inds.reference();
	acts.reference();
	nacts.reference();

	if ( redFsm->anyEofTrans() || redFsm->anyEofActions() ) {
		DECLARE( "int", klen );
		DECLARE( INDEX( ARR_TYPE( eofCondKeys ) ), ckeys );
	}

	DECLARE( UINT(), trans, " = 0" );

	if ( red->condSpaceList.length() > 0 )
		DECLARE( UINT(), cond, " = 0" );

	if ( redFsm->classMap != 0 ) {
		DECLARE( INDEX( ALPH_TYPE() ), keys );
		DECLARE( INDEX( ARR_TYPE( indicies ) ), inds );
	}

	if ( type == Loop ) {
		if ( redFsm->anyToStateActions() || redFsm->anyRegActions() ||
				redFsm->anyFromStateActions() )
		{
			DECLARE( INDEX( ARR_TYPE( actions ) ), acts );
			DECLARE( UINT(), nacts );
		}
	}
}

