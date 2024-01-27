<template>
  <el-radio-group v-model="radioData" class="group">
    <Radio v-for="(item, index) in listsData" :key="index" :label="index" :list-data="item"></Radio>
  </el-radio-group>
</template>

<script setup>
import { ref } from 'vue'

const props = defineProps({
  listsData: {
    type: Array,
    required: true
  }
})

const radioData = ref('1')
</script>

<style scoped>
.group {
  display: block;
  margin-inline: 10px;
  padding-inline: 10px;
}
</style>
