///////////////////////////////////////////////////////////////////////////////
// Copyright Christopher Kormanyos 2014.
// Copyright John Maddock 2014.
// Copyright Paul Bristow 2014.
// Distributed under the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)
//

// fixed_point_detail_constants.hpp implements templates
// for computing fixed-point representations of mathematical
// constants such as pi and log(2).

#ifndef FIXED_POINT_DETAIL_HYPERGEOMETRIC_2015_08_21_HPP_
  #define FIXED_POINT_DETAIL_HYPERGEOMETRIC_2015_08_21_HPP_

  #include <cmath>
  #include <limits>
  #include <boost/cstdint.hpp>

  namespace boost { namespace fixed_point { namespace detail {

  template<typename NumericType>
  NumericType hypergeometric_0f0(const NumericType& x)
  {
    // Compute the series representation of hypergeometric_0f0.
    // There are no checks on input range or parameter boundaries.

    // This function is designed for small-argument Taylor expansion only!
    // It is not intended for general purpose calculations of
    // hypergeometric_0f0!

    NumericType term(x);
    NumericType h0f0(1 + term);

    BOOST_CONSTEXPR_OR_CONST boost::uint32_t maximum_number_of_iterations = UINT32_C(10000);

    // Perform the series expansion of hypergeometric_0f0(; ; x).
    for(boost::uint32_t n = UINT32_C(2); n < maximum_number_of_iterations; ++n)
    {
      term *= x;
      term /= n;

      const bool minimum_number_of_iterations_is_complete = (n > UINT32_C(4));

      using std::fabs;

      if(   (minimum_number_of_iterations_is_complete)
         && (fabs(term) <= std::numeric_limits<NumericType>::epsilon()))
      {
        break;
      }

      h0f0 += term;
    }

    return h0f0;
  }

  template<typename NumericType>
  NumericType hypergeometric_0f1(const NumericType& x,
                                 const NumericType& b)
  {
    // Compute the series representation of hypergeometric_0f1.
    // There are no checks on input range or parameter boundaries.

    NumericType bp(b);

    NumericType term(x / bp);
    NumericType h0f1(1 + term);

    BOOST_CONSTEXPR_OR_CONST boost::uint32_t maximum_number_of_iterations = UINT32_C(10000);

    // Perform the series expansion of hypergeometric_0f1(; b; x).
    for(boost::uint32_t n = UINT32_C(2); n < maximum_number_of_iterations; ++n)
    {
      term *= x;
      term /= n;

      ++bp; term /= bp;

      const bool minimum_number_of_iterations_is_complete = (n > UINT32_C(4));

      using std::fabs;

      if(   (minimum_number_of_iterations_is_complete)
         && (fabs(term) <= std::numeric_limits<NumericType>::epsilon()))
      {
        break;
      }

      h0f1 += term;
    }

    return h0f1;
  }

  template<typename NumericType>
  NumericType hypergeometric_2f1(const NumericType& x,
                                 const NumericType& a,
                                 const NumericType& b,
                                 const NumericType& c)
  {
    // Compute the series representation of hyperg_2f1 taken from
    // Abramowitz and Stegun 15.1.1.
    // There are no checks on input range or parameter boundaries.

    NumericType ap(a);
    NumericType bp(b);
    NumericType cp(c);

    NumericType term(((ap * bp) / cp) * x);
    NumericType h2f1(1 + term);

    BOOST_CONSTEXPR_OR_CONST boost::uint_fast16_t maximum_number_of_iterations = UINT16_C(10000);

    // Perform the series expansion of hypergeometric_2f1(a, b; c; x).
    for(boost::uint32_t n = UINT32_C(2); n < maximum_number_of_iterations; ++n)
    {
      term *= x;
      term /= n;

      ++ap; term *= ap;
      ++cp; term /= cp;
      ++bp; term *= bp;

      const bool minimum_number_of_iterations_is_complete = (n > UINT32_C(4));

      using std::fabs;

      if(   (minimum_number_of_iterations_is_complete)
         && (fabs(term) <= std::numeric_limits<NumericType>::epsilon()))
      {
        break;
      }

      h2f1 += term;
    }

    return h2f1;
  }

  } } } // namespace boost::fixed_point::detail

#endif // FIXED_POINT_DETAIL_HYPERGEOMETRIC_2015_08_21_HPP_
