/**
* \brief Struct with basic 2D vector implementation with members *x* and *y*.
*
* Supports standard mathematical operations and comparisons.
*/

#pragma once

struct Vector2 {
	float x, y;
	
	Vector2 ( float x = 0, float y = 0 ) : x ( x ), y( y ) {}

	Vector2 operator + ( const Vector2 & other ) const {
		return Vector2( x + other.x, y + other.y );
	}

	Vector2 operator - ( const Vector2 & other ) const {
		return Vector2( x - other.x, y - other.y );
	}

	Vector2 & operator += ( const Vector2 & other ) {
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2 & operator -= ( const Vector2 & other ) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	bool operator == ( const Vector2 & other ) const {
		return x == other.x && y == other.y;
	}

	bool operator != ( const Vector2 & other ) const {
		return ! ( *this == other );
	}
};
