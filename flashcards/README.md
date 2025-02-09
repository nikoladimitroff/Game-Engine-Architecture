# Flashcards

## How to Study:
- Begin with **study-cards-top.md**: the most important study cards
- Proceed with **study-cards.md**: all study cards
- The cards are not exhaustive, going through the actual slides/videos is highly recommended!

### How to Toggle Answers
- View flashcards in an editor that supports markdown folding. Start with everything folded, unfold to check your answers.
- (E.g. Vim users, have a look at:)
```
set foldmethod=expr
set foldcolumn=0
g:markdown_folding = 1
``````

## Flashcard Generation Method

### study-cards.md
- for each document in folder *../lectures*:
  - Append content of lecture2flashcards.prompt to the document content
  - Paste into GPT prompt
  - Copy GPT's output to a file *study-cards.md*
Note: Currently, GPTs do not accept > 4000 lines of input. You may need to split large documents
Note: Because lectures start with reviews, some duplicated study content from older lectures comes up in current lecture. These duplicates are useful for gauging importance in next step.
  
### study-cards-top.md
- Append content of top-flashcards.prompt to contents of *study-cards.md*
- Paste into GPT
- Copy GPT's output to a file *study-cards-top.md*

### Finishing Touches, i.e. Manual Work:
- Find correct flashcard category for flashcards based on review questions
- Delete duplicate flashcards, if any. Duplicates occur due to review questions revisiting old study material

## TODO:
- [ ] Automate flashcard generation using LLM API
- [ ] Iterate on prompt files: Correctly identify review questions' actual lecture name during generation phase. Currently, content from previous lectures may come up if review part was also inserted in the prompt