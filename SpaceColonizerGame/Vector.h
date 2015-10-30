/*
James Felts 2015
*/
#ifndef VECTOR_H
#define VECTOR_H
#ifdef _MSC_VER
#pragma warning(disable: 4505 4514 4668 4820 4710 4711)
#endif
#include <cmath>
#define VECTOR_EQUALITY_TOLERANCE_FACTOR 10000

namespace Utils
{
	struct Vector2D
	{
		friend std::ostream& operator<<(std::ostream& out, const Vector2D& vect)
		{
			out << "(" << vect.m_x << "," << vect.m_y << ")";
			return out;
		}

		constexpr Vector2D() = default;
		Vector2D(const float x, const float y)noexcept : m_x(x), m_y(y)
		{
			updateMagnitude();
		}
		virtual ~Vector2D() noexcept{}

		//copy ctor
		Vector2D(const Vector2D& orig)noexcept
		{
			m_x = orig.m_x;
			m_y = orig.m_y;
			updateMagnitude();
		}

		//copy assign
		Vector2D operator=(const Vector2D& orig)noexcept
		{
			if(this!=&orig)
			{
				m_x = orig.m_x;
				m_y = orig.m_y;
				updateMagnitude();
			}
			return *this;
		}

		//move ctor
		Vector2D(Vector2D&& orig)noexcept:m_x(orig.m_x),m_y(orig.m_y)
		{
			updateMagnitude();
		}

		//move assign
		Vector2D operator=(Vector2D&& orig)noexcept
		{
			if (this != &orig)
			{
				m_x = orig.m_x;
				m_y = orig.m_y;
				updateMagnitude();
			}
			return *this;
		}

		float getX()const noexcept{ return m_x; }
		float getY()const noexcept{ return m_y; }
		void setX(float x) noexcept
		{
			m_x = x;
			updateMagnitude();
		}
		void setY(float y) noexcept
		{
			m_y = y;
			updateMagnitude();
		}
		float getMagnitude() const noexcept{ return m_magnitude; }
		void truncate(const float maxSize) noexcept
		{
			if (m_magnitude > maxSize)
			{
				auto ratio = maxSize / m_magnitude;
				m_y = m_y*ratio;
				m_x = m_x*ratio;
				updateMagnitude();
			}
		}

		Vector2D operator+(const Vector2D& rhs)const noexcept
		{
			Vector2D ret;
			ret.setX(this->getX() + rhs.getX());
			ret.setY(this->getY() + rhs.getY());
			return ret;
		}

		Vector2D& operator+=(const Vector2D& rhs)noexcept
		{
			setX(this->getX() + rhs.getX());
			setY(this->getY() + rhs.getY());
			return *this;
		}

		Vector2D operator-(const Vector2D& rhs)const noexcept
		{
			Vector2D ret;
			ret.setX(this->getX() - rhs.getX());
			ret.setY(this->getY() - rhs.getY());
			return ret;
		}

		Vector2D& operator-=(const Vector2D& rhs)noexcept
		{
			setX(this->getX() - rhs.getX());
			setY(this->getY() - rhs.getY());
			return *this;
		}

		bool operator==(const Vector2D& rhs) const noexcept
		{
			//avoid floating point equality problems
			long long x = static_cast<long long>(this->getX()*VECTOR_EQUALITY_TOLERANCE_FACTOR);
			long long y = static_cast<long long>(this->getY()*VECTOR_EQUALITY_TOLERANCE_FACTOR);
			long long rhsX = static_cast<long long>(rhs.getX()*VECTOR_EQUALITY_TOLERANCE_FACTOR);
			long long rhsY = static_cast<long long>(rhs.getY()*VECTOR_EQUALITY_TOLERANCE_FACTOR);

			if(x == rhsX && y == rhsY)
			{
				return true;
			}
			return false;
		}

		bool operator!=(const Vector2D& rhs) const noexcept
		{
			return !(*this == rhs);
		}

		bool equals(const Vector2D& rhs) const noexcept
		{
			return *this == rhs;
		}

		float dotProduct(const Vector2D&rhs)const noexcept
		{
			return this->m_x*rhs.m_x + this->m_y*rhs.m_y;
		}

	private:
		float m_x = 0;
		float m_y = 0;
		float m_magnitude = 0;
		void updateMagnitude() noexcept
		{
			m_magnitude = sqrtf((m_x*m_x) + (m_y*m_y));
		}

	};
}
#endif

