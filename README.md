# Grind 75 - LeetCode Problems in TypeScript

This repository contains solutions to the [Grind 75](https://www.techinterviewhandbook.org/grind75/) problems in TypeScript.

## Setup

Install dependencies:

```bash
npm install
```

## Usage

### Running Tests

Run all tests:
```bash
npm test
```

Run tests in watch mode (auto-rerun on file changes):
```bash
npm run test:watch
```

Run tests for a specific problem:
```bash
npm test 001-two-sum
```

### Adding a New Problem

1. Create a new file in `src/problems/` with the naming pattern `XXX-problem-name.ts`
   - Example: `001-two-sum.ts`

2. Add the problem description as a JSDoc comment and create the function:

```typescript
/**
 * 1. Two Sum
 * Difficulty: Easy
 * https://leetcode.com/problems/two-sum/
 *
 * Problem description here...
 */

export function twoSum(nums: number[], target: number): number[] {
  // TODO: Implement solution
  return [];
}
```

3. Create a corresponding test file `XXX-problem-name.test.ts`:

```typescript
import { twoSum } from './001-two-sum';

describe('Two Sum', () => {
  test('Example 1: description', () => {
    expect(twoSum([2, 7, 11, 15], 9)).toEqual([0, 1]);
  });

  test('Example 2: description', () => {
    expect(twoSum([3, 2, 4], 6)).toEqual([1, 2]);
  });
});
```

4. Implement your solution and run the tests!

## Project Structure

```
grind75/
├── src/
│   └── problems/
│       ├── 001-two-sum.ts          # Solution
│       ├── 001-two-sum.test.ts     # Tests
│       ├── 002-problem-name.ts
│       └── 002-problem-name.test.ts
├── package.json
├── tsconfig.json
├── jest.config.js
└── README.md
```

## Tips

- Copy test cases directly from LeetCode's examples
- Use descriptive test names to understand what each case is testing
- Start with the brute force solution, then optimize
- Add edge cases as you think of them
