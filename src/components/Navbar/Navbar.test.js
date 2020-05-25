import React from 'react';
import { render, screen } from '@testing-library/react';
import { make as Navbar } from './Navbar.bs';

test('renders the react logo', () => {
  render(<Navbar />);
  const logo = screen.getByRole(/logo/);
  expect(logo).toBeInTheDocument();
});

test('renders github handle', () => {
  render(<Navbar />);
  const handle = screen.getByText('@fa7ad');
  expect(handle).toBeInTheDocument();
})