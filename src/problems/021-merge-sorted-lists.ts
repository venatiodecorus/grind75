/**
 * 21. Merge Two Sorted Lists
 * Difficulty: Easy
 * https://leetcode.com/problems/merge-two-sorted-lists
 * You are given the heads of two sorted linked lists list1 and list2.
 * Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
 * Return the head of the merged linked list.
 */

export class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

export function mergeTwoLists(
  list1: ListNode | null,
  list2: ListNode | null,
): ListNode | null {
  if (!list1) return list2;
  if (!list2) return list1;

  if (list1.val <= list2.val) {
    list1.next = mergeTwoLists(list1.next, list2);
    return list1;
  } else {
    list2.next = mergeTwoLists(list1, list2.next);
    return list2;
  }
  // if (!list1 && !list2) return new ListNode();
  // if (!list1) return list2;
  // if (!list2) return list1;

  // let curr;
  // if(list1.val < list2.val) {
  //   curr = list1;
  // } else {
  //   curr = list2;
  // }

  // while(list1.next || list2.next) {
  //   if(list1.val <= list2.val) {

  //   }
  // }
}
