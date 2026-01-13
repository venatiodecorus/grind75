import { mergeTwoLists, ListNode } from "./021-merge-sorted-lists";

// Helper function to convert array to linked list
function arrayToList(arr: number[]): ListNode | null {
  if (arr.length === 0) return null;

  const head = new ListNode(arr[0]);
  let current = head;

  for (let i = 1; i < arr.length; i++) {
    current.next = new ListNode(arr[i]);
    current = current.next;
  }

  return head;
}

// Helper function to convert linked list to array
function listToArray(head: ListNode | null): number[] {
  const result: number[] = [];
  let current = head;

  while (current !== null) {
    result.push(current.val);
    current = current.next;
  }

  return result;
}

describe("Merge Two Sorted Lists", () => {
  test("Example 1: list1 = [1,2,4], list2 = [1,3,4]", () => {
    const list1 = arrayToList([1, 2, 4]);
    const list2 = arrayToList([1, 3, 4]);
    const merged = mergeTwoLists(list1, list2);
    expect(listToArray(merged)).toEqual([1, 1, 2, 3, 4, 4]);
  });

  test("Example 2: list1 = [], list2 = []", () => {
    const list1 = arrayToList([]);
    const list2 = arrayToList([]);
    const merged = mergeTwoLists(list1, list2);
    expect(listToArray(merged)).toEqual([]);
  });

  test("Example 3: list1 = [], list2 = [0]", () => {
    const list1 = arrayToList([]);
    const list2 = arrayToList([0]);
    const merged = mergeTwoLists(list1, list2);
    expect(listToArray(merged)).toEqual([0]);
  });
});
