#include<iostream>
#include<deque>


struct bigint{
	std::deque< int > numbers;

	bigint( void ) : bigint( 0 ){};

	bigint( size_t str ) {
		while( str ){
			numbers.push_front( static_cast<int>( str % 10 ) );
			str /= 10;
		}
		if( numbers.empty() )
			numbers.push_back( 0 );
	};

	bigint( const bigint& og ) : numbers( og.numbers ) {};

	bigint& operator=( const bigint& og ){
		if( this != &og )
			numbers = og.numbers;
		return( *this );
	};

	~bigint( void ) {};

	bigint operator+( const bigint& other ) const{
		bigint smaller;
		bigint bigger;
		if( numbers.size() < other.numbers.size() ){
			smaller = *this;
			bigger = other;
		}
		else{
			smaller = other;
			bigger = *this;
		}

		size_t offset = bigger.numbers.size() - smaller.numbers.size();
		int	carry = 0;

		for( int i = smaller.numbers.size() - 1; i > -1; --i ){

			int	j = i + offset;

			int	sol = smaller.numbers[ i ] + bigger.numbers[ j ];

			if( sol > 9 ){
				sol /= 10;
				carry = 1;
			}

			bigger.numbers[ j ] = sol;

			if( carry ){
				bigger.numbers[ j ]++;
				carry = 0;
			}	
		}
		return( bigger );
	};

	bigint operator+=( const bigint& other ){
		*this = *this + other;
		return( *this );
	};

	bigint operator++( void ){
		bigint other( 1 );
		*this += other;
		return( *this );
	};

	bigint operator++( int ){
		bigint copy( *this );
		bigint other( 1 );
		*this += other;
		return( copy );
	};

	bigint operator<<( const bigint& other ){
		bigint copy( *this );

		if( other.numbers.size() == 1 && other.numbers[0] == 0 )
			return( copy );		
		for( bigint i; i < other; ++i ){
			numbers.push_back( 0 );
		}
		return( copy );
	};

	bigint operator<<( const int other ){
		bigint copy( *this );

		for( int i = 0; i < other; ++i ){
			numbers.push_back( 0 );
		}
		return( copy );
	};

	bigint operator<<=( const bigint& other ){
		if( other.numbers.size() == 1 && other.numbers[0] == 0 )
			return( *this );		
		for( bigint i; i < other; ++i ){
			numbers.push_back( 0 );
		}
		return( *this );
	};

	bigint operator<<=( const int other ){
		for( int i = 0; i < other; ++i ){
			numbers.push_back( 0 );
		}
		return( *this );
	};

	bigint operator>>( const bigint& other ){
		bigint copy( *this );

		for( bigint i; i < other; ++i ){
			if( !numbers.empty() )
				numbers.pop_back();
			else{
				numbers.push_front( 0 );
				break;
			}
		}
		return( copy );
	};

	bigint operator>>( const int other ){
		bigint copy( *this );

		for( int i = 0; i < other; ++i ){
			if( !numbers.empty() )
				numbers.pop_back();
			else{
				numbers.push_front( 0 );
				break;
			}
		}
		return( copy );
	};

	bigint operator>>=( const bigint& other ){
		for( bigint i; i < other; ++i ){
			if( !numbers.empty() )
				numbers.pop_back();
			else{
				numbers.push_front( 0 );
				break;
			}
		}
		return( *this );
	};

	bigint operator>>=( const int other ){
		for( int i = 0; i < other; ++i ){
			if( !numbers.empty() )
				numbers.pop_back();
			else{
				numbers.push_front( 0 );
				break;
			}
		}
		return( *this );
	};

	bool operator>( bigint other ){
		if( numbers.size() > other.numbers.size() )
			return( true );
		else if( numbers.size() < other.numbers.size() )
			return( false );
		for( size_t i = 0; i < numbers.size(); ++i ){
			if( numbers[i] > other.numbers[i] )
				return( true );
			else if ( numbers[i] < other.numbers[i] )
				return( false );
		}
		return( false );
	};

	bool operator>=( bigint other ){
		if( numbers.size() > other.numbers.size() )
			return( true );
		else if( numbers.size() < other.numbers.size() )
			return( false );
		for( size_t i = 0; i < numbers.size(); ++i ){
			if( numbers[i] > other.numbers[i] )
				return( true );
			else if ( numbers[i] < other.numbers[i] )
				return( false );
		}
		return( true );
	};

	bool operator<( bigint other ){
		return( !( *this >= other ) );
	};

	bool operator<=( bigint other ){
		return( !( *this > other ) );
	};

	bool operator==( bigint other ){
		return( ( *this >= other ) && ( *this <= other ) );
	};

	bool operator!=( bigint other ){
		return( !( *this == other ) );
	};
};

std::ostream& operator<<( std::ostream&, const bigint );
