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
		Fixed(const Fixed &other);
		~Fixed();
		Fixed &operator=(const Fixed &other);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};


#endif