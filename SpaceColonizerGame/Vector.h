/*
James Felts 2015
*/
#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
namespace Utils
{
	struct Vector
	{
		friend inline std::ostream& operator<<(std::ostream& out, const Vector& vect)
		{
			out << "(" << vect.m_x << "," << vect.m_y << ")";
			return out;
		}

		constexpr Vector() = default;
		virtual ~Vector() noexcept{}
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
				float ratio = maxSize / m_magnitude;
				m_y = m_y*ratio;
				m_x = m_x*ratio;
			}
		}

		Vector operator+(const Vector& rhs)
		{
			Vector ret;
			ret.setX(this->getX() + rhs.getX());
			ret.setY(this->getY() + rhs.getY());
			return ret;
		}

		Vector& operator+=(const Vector& rhs)
		{
			setX(this->getX() + rhs.getX());
			setY(this->getY() + rhs.getY());
			return *this;
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

