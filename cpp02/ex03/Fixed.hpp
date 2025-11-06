#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int m_fp_number;
		static const int m_fractional_bits;
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed &);

		~Fixed();

		Fixed &operator=(const Fixed &);
		Fixed operator+(const Fixed &) const;
		Fixed operator-(const Fixed &) const;
		Fixed operator*(const Fixed &) const;
		Fixed operator/(const Fixed &) const;
		bool operator>(const Fixed &) const;
		bool operator<(const Fixed &) const;
		bool operator>=(const Fixed &) const;
		bool operator<=(const Fixed &) const;
		bool operator==(const Fixed &) const;
		bool operator!=(const Fixed &) const;

		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		int getRawBits( void ) const;
		void setRawBits( int const );

		float toFloat(void) const;
		int toInt(void) const;

		static const Fixed	&min(Fixed const &, Fixed const &);
		static const Fixed	&max(Fixed const &, Fixed const &);
		static Fixed		abs(Fixed const &);
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif