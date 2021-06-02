/** \file bufferLayout.h
*/
#pragma once

#include "bufferElement.h"

#include <vector>

namespace Engine
{
	/**
	\class BufferLayout
	\brief Stores the buffer elements and calculates the layout
	*/
	class BufferLayout
	{
	private:
		std::vector<BufferElement> m_elements; //!< The buffer elements
		unsigned int m_iStride; //!< The stride
		void calcStrideAndOffsets(); //!< Used to calculate the stride and the offsets
	public:
		//! Default constructor
		BufferLayout() {}
		//! Constructor
		/*!
		\param elements A list of buffer elements
		*/
		BufferLayout(const std::initializer_list<BufferElement>& elements);

		//! Used to get the stride
		/*!
		\return The stride
		*/
		inline unsigned int getStride() const { return m_iStride; }

		//! Used to set an iterator to the start of the vector
		/*!
		\return An iterator at the start of the vector
		*/
		std::vector<BufferElement>::iterator begin() { return m_elements.begin(); }
		//! Used to set an iterator to the end of the vector
		/*!
		\return An iterator at the end of the vector
		*/
		std::vector<BufferElement>::iterator end() { return m_elements.end(); }
		//! Used to set an iterator to the start of the vector
		/*!
		\return An iterator at the start of the vector
		*/
		std::vector<BufferElement>::const_iterator begin() const { return m_elements.begin(); }
		//! Used to set an iterator to the end of the vector
		/*!
		\return An iterator at the end of the vector
		*/
		std::vector<BufferElement>::const_iterator end() const { return m_elements.end(); }

		//! Used to add an element to the layout
		/*!
		\param dataType The type of data of the element being added
		*/
		void addElement(ShaderDataType dataType);
	};
}