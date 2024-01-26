<template>
  <el-radio-group v-model="radioData" class="group">
    <Radio label="1"></Radio>
    <Radio label="2"></Radio>
    <Radio label="3"></Radio>
    <Radio label="4"></Radio>
    <Radio label="5"></Radio>
    <Radio label="6"></Radio>
    <Radio label="7"></Radio>

  </el-radio-group>
</template>

<script setup>
import { ref } from 'vue'
import Radio from './Radio.vue'

const radioData = ref('1')
</script>


<style scoped>
.group {
  display: block;
}
</style>