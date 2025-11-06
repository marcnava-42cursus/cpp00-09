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
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed &other);
		~Fixed();
		Fixed &operator=(const Fixed &other);

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif