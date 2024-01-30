<template>
  <div class="container">
    <!-- 标题 -->
    <Head class="title" :name="title" middle="true"></Head>

    <div class="content">
      <!-- 表单 -->
      <div class="form">
        <slot name="form">表单</slot>
      </div>

      <!-- 表格 -->
      <div class="table">
        <slot name="table">表格</slot>
      </div>
    </div>

    <div class="page">
      <!-- 分页 -->
      <slot name="page">分页</slot>
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import Head from '@/components/head/Head.vue'
// import { ref } from 'vue'
// import { ArrowUp, ArrowDown } from '@element-plus/icons-vue'

const props = defineProps({
  title: {
    type: String,
    default: '标题'
  }
})
</script>

<style lang="scss" scoped>
.container {
  height: 100%;
  overflow: hidden;
  .title {
    margin: 0;
  }
  .content {
    padding: 10px 0;
    padding-bottom: 50px;
    height: calc(100% - 50px);
    border: solid 1px var(--el-border-color);
    .form {
        padding-bottom: 10px;
    }
    .table {
      padding: 0 10px;
      height: calc(100% - 150px);
      overflow: auto;
    }
  }
  .page {
    width: 100%;
    position: absolute;
    display: flex;
    justify-content: center;
    bottom: 16px;
  }
}

.form,
.page {
  padding: 0 16px;
}
</style>
