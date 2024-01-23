<!-- 体检报告 -->
<template>
  <div>
    <el-container>
      <el-aside>
        <PeoplleList title="人员查询"></PeoplleList>
      </el-aside>
      <el-main>
        <Head name="报告预览"></Head>
        <div class="pdf">
          <PdfObject></PdfObject>
        </div>
      </el-main>
    </el-container>
  </div>
</template>

<script setup>
import PeoplleList from '@/components/peoplelist/PeopleList.vue'
import PdfObject from '@/components/pdfobject/PdfObject.vue'
import Head from '@/components/head/Head.vue'
</script>

<style lang="scss" scoped>
.head {
  font-weight: bold;
}
</style>
